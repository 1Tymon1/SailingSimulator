// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "SailingBoat.generated.h"

UCLASS()
class SAILINGSIMULATOR_API ASailingBoat : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASailingBoat();
	// Called every frame
	virtual void Tick(float DeltaTime) override; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Boat")
    UStaticMeshComponent* BoatMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Physics")
    float LinearDamping = 0.8f; // opór wody (ruch)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Physics")
    float AngularDamping = 4.0f;    // opór wody (obrót)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Physics")
    float WaterZ = 0.0f; // poziom wody

public:
	
    //SKRET
    UPROPERTY(BlueprintReadWrite, Category="Boat|Input")
    float SteeringInput = 0.0f;

    //NAPED
    UPROPERTY(BlueprintReadWrite, Category="Boat|Input")
    float ThrottleInput = 0.0f;

    UFUNCTION(BlueprintCallable, Category="Boat|Input")
    void SetDriveInput(float Steering, float Throttle);

    //MOVEMENT
    //MAX SILA NAPED
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Movement")
    float MaxForwardForce = 5000.0f;

    //MAX SILA SKRET
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Movement")
    float MaxTurnTorque = 4500000000.0f;

    //MAX SPEED
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Movement")
    float MaxSpeed = 1500.0f;

    //ROCKING
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Rocking")
    float WaveRockingStrength = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Rocking")
    float WindRockingStrength = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Rocking")
    float TurnRockingStrength = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Rocking")
    float RockingSpeed = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Rocking")
    float MaxRockingAngle = 15.0f;

    //Wind
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Wind")
    FVector WindDirection = FVector(1.0f, 0.0f, 0.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boat|Wind")
    float WindStrength = 0.0f;

private:
    void ApplyDrive(float DeltaTime);
    void ApplySpeedLimit();

    void ApplyRocking(float DeltaTime);
    void ApplyBuoyancy(float DeltaTime);

    float RockingTime = 0.0f;
    float CurrentRollAngle = 0.0f;
    float CurrentPitchAngle = 0.0f;
};