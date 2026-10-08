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

void ABoatSphereController::TryConnect(){
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this]()
    {
        
    });
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

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(20, 0.0f, FColor::Cyan,
			FString::Printf(TEXT("SPHERE: velocity=%.2f direction=%.2f"),
				event.velocity, event.direction));
	}
}

void ABoatSphereController::SendBoatDataToSphere(float DeltaTime)
{
	if(!BoatRef) return;
	if(!IsConnected()) return;

	
	FVector Velocity = BoatRef->BoatMesh->GetPhysicsLinearVelocity();
    FVector Acceleration = (Velocity - PreviousVelocity) / DeltaTime;
    PreviousVelocity = Velocity;

	float NormalizedVX = FMath::Clamp(Velocity.X / 1500.0f, -1.0f, 1.0f);
    float NormalizedVY = FMath::Clamp(Velocity.Y / 1500.0f, -1.0f, 1.0f);
    float NormalizedWZ = FMath::Clamp(
        BoatRef->BoatMesh->GetPhysicsAngularVelocityInDegrees().Z 
        / 90.0f, -1.0f, 1.0f);

	SetSphereVector(NormalizedVX, NormalizedVY, NormalizedWZ);

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(21, 0.0f, FColor::Yellow,
			FString::Printf(TEXT("To sphere: vx=%.2f vy=%.2f wz=%.2f"),
				NormalizedVX, NormalizedVY, NormalizedWZ));
	}
}
