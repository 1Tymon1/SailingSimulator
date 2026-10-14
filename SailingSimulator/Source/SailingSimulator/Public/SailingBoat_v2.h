// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "BuoyancyComponent.h"
#include "SailingBoat_v2.generated.h"

UCLASS()
class SAILINGSIMULATOR_API ASailingBoat_v2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASailingBoat_v2();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Boat")
	UStaticMeshComponent* BoatMesh;

	UPROPERTY(EditAnywhere, Category="Boat|Movement")
	float MaxForwardForce = 2000.0f;

	UPROPERTY(EditAnywhere, Category="Boat|Movement")
	float MaxTurnTorque = 100.0f;

	UPROPERTY(EditAnywhere, Category="Boat|Movement")
	float MaxSpeed = 1500.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Boat")
	UBuoyancyComponent* BuoyancyComponent;

	// Sterring wheel
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Steering Wheel")
    USceneComponent* SteeringWheelPivot = nullptr;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Steering Wheel")
    UStaticMeshComponent* SteeringWheelVisual = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Steering Wheel")
	UBoxComponent* SteeringWheelHitbox = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Steering Wheel")
    float MaxSteeringWheelAngle = 450.0f;

    UFUNCTION(BlueprintCallable, Category = "Steering Wheel")
    void SetSteeringWheelAngle(float NewAngle);
	float GetSteeringWheelAngle();

	void SetThrottle(float value);
	void SetSteering(float value);

private:
	float ThrottleInput = 0.0f;
	float SteeringInput = 0.0f;
	float DesiredYaw = 0.0f;

	float SteeringWheelAngle = 0.0f;

	void ApplyDrive(float DeltaTime);
	void ApplySpeedLimit();
	void KeepUpright(float DeltaTime);
	void UpdatePlayerPosition(float DeltaTime);
	void DrawPontoons();
	void LockYawFromPlayer();
};
