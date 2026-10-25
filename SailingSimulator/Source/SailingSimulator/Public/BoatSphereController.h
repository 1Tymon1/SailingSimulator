// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AVirtuSphereController.h"
#include "SailingBoat_v2.h"
#include "BoatSphereController.generated.h"

UCLASS()
class SAILINGSIMULATOR_API ABoatSphereController : public AVirtuSphereController
{
	GENERATED_BODY()
	
public:
	ABoatSphereController();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void OnSpherePose_Implementation(FSpherePoseEvent event) override;

private:
	ASailingBoat_v2* BoatRef = nullptr;
	FVector PreviousVelocity = FVector::ZeroVector;
	float SendTimer = 0.0f;
	float ReconnectTimer = 0.0f;

	FVector PlayerWalkVector = FVector::ZeroVector;

	void FindBoat();
	void SendBoatDataToSphere(float DeltaTime);
};
