// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SailingBoat_v2.h"
#include "BoatPlayerController.generated.h"

class USceneComponent;

UCLASS()
class SAILINGSIMULATOR_API ABoatPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ABoatPlayerController();
    virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	ASailingBoat_v2* BoatRef = nullptr;

    UPROPERTY()
    ASailingBoat_v2* SteeringBoatRef = nullptr;

    bool bIsSteeringWheelDragging = false;
    bool bSteeringInteractionMode = false;

    void ToggleSteeringInteractionMode();

    float MouseSteeringSensitivity = 1.5f;

    void BeginSteeringWheelDrag();
    void EndSteeringWheelDrag();
    void UpdateSteeringWheelDrag();


    USceneComponent* CameraPivot = nullptr;
    float CameraBoatRoll = 0.0f;
    float CameraBoatPitch = 0.0f;

	// WASD — postaæ
    void MoveForward(float Value);
    void MoveRight(float Value);

    // Strza³ki — ³ódka
    void BoatForward(float Value);
    void BoatTurn(float Value);

    // Mysz — kamera
    void LookYaw(float Value);
    void LookPitch(float Value);

    void UpdateBoatCameraMotion(float DeltaTime);
};
