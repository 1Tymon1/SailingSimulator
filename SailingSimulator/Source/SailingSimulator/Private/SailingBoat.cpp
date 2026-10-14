// Fill out your copyright notice in the Description page of Project Settings.


#include "SailingBoat.h"

// Sets default values
ASailingBoat::ASailingBoat()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoatMesh"));
	RootComponent = BoatMesh;

	BoatMesh->SetSimulatePhysics(true);
    BoatMesh->SetLinearDamping(LinearDamping);
    BoatMesh->SetAngularDamping(AngularDamping);

	// BoatMesh->GetBodyInstance()->bLockXRotation = true;
 //    BoatMesh->GetBodyInstance()->bLockYRotation = true;
}

// Called when the game starts or when spawned
void ASailingBoat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASailingBoat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ApplyDrive(DeltaTime);
	ApplySpeedLimit();
	// ApplyRocking(DeltaTime);
	// ApplyBuoyancy(DeltaTime);
}

void ASailingBoat::SetDriveInput(float Steering, float Throttle)
{
    SteeringInput = FMath::Clamp(Steering, -1.0f, 1.0f);
    ThrottleInput = FMath::Clamp(0.0f, Throttle, 0.0f);
}

void ASailingBoat::ApplyDrive(float DeltaTime)
{
    if (!FMath::IsNearlyZero(ThrottleInput))
    {
        float CurrentMass = BoatMesh->GetMass();
        FVector ForwardForce = GetActorForwardVector() * ThrottleInput * MaxForwardForce * CurrentMass;
        BoatMesh->AddForce(ForwardForce);

        // Print — kierunek i siła
        FString Msg = FString::Printf(TEXT("Forward: X=%.1f Y=%.1f Z=%.1f | Sila: %.1f"), 
            GetActorForwardVector().X, 
            GetActorForwardVector().Y,
            GetActorForwardVector().Z,
            ForwardForce.Size());
        GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, Msg);
    }

    // if (!FMath::IsNearlyZero(SteeringInput))
    // {
    //     float Speed = BoatMesh->GetPhysicsLinearVelocity().Size();
    //     float SteerEfficiency = FMath::Clamp(Speed / 300.0f, 0.0f, 1.0f);
    //     FVector TurnTorque = FVector(0.0f, 0.0f, SteeringInput * MaxTurnTorque * SteerEfficiency);
    //     BoatMesh->AddTorqueInDegrees(TurnTorque);

    //     Print — skręt i efektywność
    //     FString Msg = FString::Printf(TEXT("Skret: %.2f | Efektywnosc: %.2f | Predkosc: %.1f"), 
    //         SteeringInput, 
    //         SteerEfficiency,
    //         Speed);
    //     GEngine->AddOnScreenDebugMessage(2, 0.0f, FColor::Yellow, Msg);
    // }

    // Print zawsze — Yaw i prędkość
    FString Always = FString::Printf(TEXT("TEST12 Yaw: %.1f | Predkosc: %.1f | Throttle: %.2f"), 
        GetActorRotation().Yaw,
        BoatMesh->GetPhysicsLinearVelocity().Size(),
        ThrottleInput);
    GEngine->AddOnScreenDebugMessage(3, 0.0f, FColor::Cyan, Always);
}

void ASailingBoat::ApplySpeedLimit(){
	FVector Velocity = BoatMesh->GetPhysicsLinearVelocity();
	float Speed = Velocity.Size();

	if(Speed > MaxSpeed){
		BoatMesh->SetPhysicsLinearVelocity(Velocity.GetSafeNormal()*MaxSpeed);
	}
}

void ASailingBoat::ApplyRocking(float DeltaTime){
	RockingTime += DeltaTime;

	float WaveRoll = FMath::Sin(RockingTime * RockingSpeed * 1.1f) * WaveRockingStrength;
	float WavePitch = FMath::Sin(RockingTime * RockingSpeed * 0.7f) * WaveRockingStrength * 0.6f;

	FVector LocalWind = GetActorTransform().InverseTransformVector(WindDirection);
	float WindRoll = LocalWind.Y * WindStrength * WindRockingStrength;

	float TurnRoll = -SteeringInput * (BoatMesh->GetPhysicsLinearVelocity().Size() / MaxSpeed) * TurnRockingStrength * 10.0f;

	float TargetRoll = WaveRoll + WindRoll + TurnRoll;
	float TargetPitch = WavePitch;

	TargetRoll = FMath::Clamp(TargetRoll, -MaxRockingAngle, MaxRockingAngle);
	TargetPitch = FMath::Clamp(TargetPitch, -MaxRockingAngle, MaxRockingAngle);

	FRotator CurrentRotation = GetActorRotation();

	FRotator NewRotation = FRotator(CurrentPitchAngle, CurrentRotation.Yaw, CurrentRollAngle);

	BoatMesh->SetWorldRotation(NewRotation);
}
