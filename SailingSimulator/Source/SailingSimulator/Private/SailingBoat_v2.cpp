// Fill out your copyright notice in the Description page of Project Settings.
#include "SailingBoat_v2.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ASailingBoat_v2::ASailingBoat_v2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoatMesh"));

	// BoatMesh->GetBodyInstance()->bLockXRotation = true;
    // BoatMesh->GetBodyInstance()->bLockYRotation = true;

    BuoyancyComponent = CreateDefaultSubobject<UBuoyancyComponent>(TEXT("Buoyancy"));
}

// Called when the game starts or when spawned
void ASailingBoat_v2::BeginPlay()
{
	Super::BeginPlay();
	
    if (!BoatMesh)
    {
        return;
    }

    BoatMesh->SetSimulatePhysics(true);
	BoatMesh->SetLinearDamping(0.8f);
	BoatMesh->SetAngularDamping(8.0f);
	BoatMesh->SetEnableGravity(true);
    BoatMesh->SetMassOverrideInKg(NAME_None, 400.0f);

    {
        TArray<USceneComponent*> Components;
        GetComponents<USceneComponent>(Components);

        for (USceneComponent* Component : Components)
        {
            if (!Component)
            {
                continue;
            }

            const FName ComponentName = Component->GetFName();

            if (ComponentName == TEXT("SteeringWheelPivot_1"))
            {
                SteeringWheelPivot = Component;
            }
            else if (ComponentName == TEXT("SteeringWheelVisual_1"))
            {
                SteeringWheelVisual =
                    Cast<UStaticMeshComponent>(Component);
            }
            else if (ComponentName == TEXT("SteeringWheelHitbox_1"))
            {
                SteeringWheelHitbox =
                    Cast<UBoxComponent>(Component);
            }
        }

        if (!SteeringWheelPivot)
        {
            UE_LOG(LogTemp, Warning,
                TEXT("SteeringWheelPivot not found on %s"),
                *GetName());
        }

        if (!SteeringWheelVisual)
        {
            UE_LOG(LogTemp, Warning,
                TEXT("SteeringWheelVisual not found on %s"),
                *GetName());
        }

        if (!SteeringWheelHitbox)
        {
            UE_LOG(LogTemp, Warning,
                TEXT("SteeringWheelHitbox not found on %s"),
                *GetName());
        }
    }
}

// Called every frame
void ASailingBoat_v2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ApplyDrive(DeltaTime);
	ApplySpeedLimit();
    // KeepUpright(DeltaTime);
    // UpdatePlayerPosition(DeltaTime);
    DrawPontoons();
    LockYawFromPlayer();
}

void ASailingBoat_v2::LockYawFromPlayer()
{
    FVector AngularVel = BoatMesh->GetPhysicsAngularVelocityInDegrees();
    
    if (FMath::IsNearlyZero(SteeringInput))
    {
        AngularVel.Z = FMath::Clamp(AngularVel.Z, -5.0f, 5.0f);
        BoatMesh->SetPhysicsAngularVelocityInDegrees(AngularVel);
    }

    DesiredYaw = BoatMesh->GetComponentRotation().Yaw;
}

void ASailingBoat_v2::DrawPontoons(){
    if (!BuoyancyComponent) return;

    for (FSphericalPontoon& Pontoon : BuoyancyComponent->BuoyancyData.Pontoons)
    {
        // Oblicz pozycjê œwiatow¹ pontonu
        FVector WorldPos = GetActorTransform().TransformPosition(
                               Pontoon.RelativeLocation);

        DrawDebugSphere(
            GetWorld(),
            WorldPos,
            Pontoon.Radius,  // rozmiar sfery debug
            8,
            FColor::Green,
            false,
            0.0f
        );
    }
}

void ASailingBoat_v2::UpdatePlayerPosition(float DeltaTime){
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if(!PC) return;

    APawn* PlayerPawn = PC->GetPawn();
    if(!PlayerPawn) return;

    FVector BoatLocation = GetActorLocation();
    FRotator BoatRotation = GetActorRotation();

    FVector LocalOffset = FVector(0.0f, 0.0f, 50.0f);
    FVector WorldOffset = BoatRotation.RotateVector(LocalOffset);

    FVector CurrentPlayerPos = PlayerPawn->GetActorLocation();
    FVector NewPlayerPos = FVector(
        BoatLocation.X + WorldOffset.X,
        BoatLocation.Y + WorldOffset.Y,
        CurrentPlayerPos.Z
    );

    PlayerPawn->SetActorLocation(NewPlayerPos, true);
}

void ASailingBoat_v2::KeepUpright(float DeltaTime){
    FVector Velocity = BoatMesh->GetPhysicsLinearVelocity();
    Velocity.Z = FMath::Clamp(Velocity.Z, -50.0f, 200.0f);
    BoatMesh->SetPhysicsLinearVelocity(Velocity);
}

void ASailingBoat_v2::SetThrottle(float value){
	ThrottleInput = FMath::Clamp(value, -1.0f, 1.0f);
}

void ASailingBoat_v2::UpdateSteeringValue(){
    if(!FMath::IsNearlyZero(KeyboardSteeringInput)){
        SteeringInput = KeyboardSteeringInput;
    }
    else{
        SteeringInput = SteeringWheelInput;
    }
}

void ASailingBoat_v2::SetSteering(float value){
    KeyboardSteeringInput = FMath::Clamp(value, -1.0f, 1.0f);
	UpdateSteeringValue(); 
}

void ASailingBoat_v2::SetSteeringWheelAngle(float NewAngle){
    SteeringWheelAngle = FMath::Clamp(
        NewAngle,
        -MaxSteeringWheelAngle,
        MaxSteeringWheelAngle
    );

    SteeringWheelPivot->SetRelativeRotation(FRotator(SteeringWheelAngle, 0.0f, 0.0f));

    SteeringWheelInput = MaxSteeringWheelAngle > 0.0f ? SteeringWheelAngle / MaxSteeringWheelAngle : 0.0f;

    UpdateSteeringValue();
}

float ASailingBoat_v2::GetSteeringWheelAngle()
{
    return SteeringWheelAngle;
}

void ASailingBoat_v2::ApplyDrive(float deltaTime){

// Debug — poka¿ wszystkie wektory
    DrawDebugLine(GetWorld(), GetActorLocation(),
        GetActorLocation() + GetActorForwardVector() * 300.0f,
        FColor::Red, false, 0.0f, 0, 5.0f);    // Czerwony = Forward (X)

    DrawDebugLine(GetWorld(), GetActorLocation(),
        GetActorLocation() + GetActorRightVector() * 300.0f,
        FColor::Green, false, 0.0f, 0, 5.0f);   // Zielony = Right (Y)

    DrawDebugLine(GetWorld(), GetActorLocation(),
        GetActorLocation() + GetActorUpVector() * 300.0f,
        FColor::Blue, false, 0.0f, 0, 5.0f);    // Niebieski = Up (Z)

	if(!FMath::IsNearlyZero(ThrottleInput)){
		float Mass = BoatMesh->GetMass();
        FVector Force = -GetActorRightVector() 
                        * ThrottleInput 
                        * MaxForwardForce 
                        * Mass;
        BoatMesh->AddForce(Force);

        if (GEngine) {
            GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green,
                FString::Printf(TEXT("Throttle: %.2f | Predkosc: %.1f"),
                    ThrottleInput,
                    BoatMesh->GetPhysicsLinearVelocity().Size()));
        }
	}

	if (!FMath::IsNearlyZero(SteeringInput))
    {
        float Speed = BoatMesh->GetPhysicsLinearVelocity().Size();
        float Efficiency = FMath::Clamp(Speed / 300.0f, 0.0f, 1.0f);
        FVector Torque = FVector(0.0f, 0.0f, 
                                  SteeringInput * MaxTurnTorque * Efficiency);
        BoatMesh->AddTorqueInDegrees(Torque, NAME_None, true);
        DesiredYaw = BoatMesh->GetComponentRotation().Yaw;

        if (GEngine) {
            GEngine->AddOnScreenDebugMessage(2, 0.0f, FColor::Yellow,
            FString::Printf(TEXT("Steering: %.2f | Torque: %.1f | Speed: %.1f | Efficiency: %.1f"),
                SteeringInput, MaxTurnTorque, Speed, Efficiency));
        }
    }
    else{
        DesiredYaw = BoatMesh->GetComponentRotation().Yaw;
    }
}

void ASailingBoat_v2::ApplySpeedLimit()
{
    FVector Velocity = BoatMesh->GetPhysicsLinearVelocity();
    if (Velocity.Size() > MaxSpeed)
    {
        BoatMesh->SetPhysicsLinearVelocity(
            Velocity.GetSafeNormal() * MaxSpeed);
    }
}

