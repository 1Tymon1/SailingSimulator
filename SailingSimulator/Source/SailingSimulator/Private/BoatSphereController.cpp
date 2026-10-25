// Fill out your copyright notice in the Description page of Project Settings.


#include "BoatSphereController.h"
#include "SailingBoat_v2.h"
#include "Kismet/GameplayStatics.h"

ABoatSphereController::ABoatSphereController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABoatSphereController::BeginPlay()
{
	Super::BeginPlay();
	FindBoat();
	
	Connect("127.0.0.1", 4445);

	if (IsConnected()){
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green,
				TEXT("SphereController: Emulator connected")
			);
		}
		RequestSpherePoseUpdates(30);
	}
}

void ABoatSphereController::FindBoat()
{
	AActor* Found = UGameplayStatics::GetActorOfClass(
		GetWorld(), ASailingBoat_v2::StaticClass()
	);

	if(Found){
		BoatRef = Cast<ASailingBoat_v2>(Found);
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green,
				TEXT("SphereController: Boat founded")
			);
		}
	}
	else{
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red,
				TEXT("SphereController: No boat")
			);
		}
	}
}

void ABoatSphereController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

	// if(!IsConnected()){
	// 	ReconnectTimer += DeltaTime;
	// 	if( ReconnectTimer >= 10.0f){
	// 		ReconnectTimer = 0.0f;
	// 		Connect("127.0.0.1", 4445);
	// 	}
	// 	return;
	// }
	SendBoatDataToSphere(DeltaTime);
}

void ABoatSphereController::OnSpherePose_Implementation(FSpherePoseEvent event)
{
	if(!BoatRef) return;

	PlayerWalkVector = FVector(event.velocity, event.direction, 0.0f);

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC) return;

	APawn* PlayerPawn = PC->GetPawn();

	FRotator YawOnly = FRotator(0.0f, PC->GetControlRotation().Yaw, 0.0f);

	FVector WalkDir = YawOnly.RotateVector(FVector(
		event.actualVelocityVectorX,
		event.actualVelocityVectorY,
		0.0f
	));

	FVector PlayerPos = PlayerPawn->GetActorLocation();
	FVector NewLocation = PlayerPos + WalkDir * 100.0f * GetWorld()->GetDeltaSeconds();

	PlayerPawn->SetActorLocation(NewLocation, true);

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(20, 0.0f, FColor::Red,
			FString::Printf(TEXT("SPHERE: velocity=%.2f direction=%.2f"),
				event.velocity, event.direction));
	}
}

void ABoatSphereController::SendBoatDataToSphere(float DeltaTime)
{
	if(!BoatRef || !IsConnected()) return;

	FRotator BoatRotation = BoatRef->GetActorRotation();

	
	FVector Velocity = BoatRef->BoatMesh->GetPhysicsLinearVelocity();
    FVector Acceleration = (Velocity - PreviousVelocity) / DeltaTime;
    PreviousVelocity = Velocity;

	FVector LocalAccel = BoatRef->GetActorTransform().InverseTransformVector(Acceleration);

	float AccelForward = LocalAccel.X / 100.0f;
	float AccelRight = LocalAccel.Y / 100.0f;

	float PlatformPitch = FMath::Clamp(BoatRotation.Pitch, -30.0f, 30.0f);
	float PlatformRoll = FMath::Clamp(BoatRotation.Roll, -30.0f, 30.0f);
	float BoatYawSpeed = BoatRef->BoatMesh->GetPhysicsAngularVelocityInDegrees().Z;
	
	float PlatformVX = FMath::Clamp((PlatformRoll / 30.0f) * 1.0f + AccelRight * 0.1f, -1.0f, 1.0f);
	float PlatformVY = FMath::Clamp((PlatformPitch / 30.0f) * 1.0f + AccelForward * 0.1f, -1.0f, 1.0f);
	float PlatformWZ = FMath::Clamp(FMath::DegreesToRadians(BoatYawSpeed) * 0.5f, -1.0f, 1.0f);

	if (!FMath::IsFinite(PlatformVX)) PlatformVX = 0.0f;
	if (!FMath::IsFinite(PlatformVY)) PlatformVY = 0.0f;
	if (!FMath::IsFinite(PlatformWZ)) PlatformWZ = 0.0f;

	SetSphereVector(PlatformVX, PlatformVY, PlatformWZ);

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(21, 0.0f, FColor::Yellow,
			FString::Printf(
				TEXT("BoatSphereController | Platform: pitch=%.1f roll=%.1f yaw=%.1f | vx=%.2f vy=%.2f wz=%.2f"),
				PlatformPitch, PlatformRoll, BoatYawSpeed,
				PlatformVX, PlatformVY, PlatformWZ));
	}
}
