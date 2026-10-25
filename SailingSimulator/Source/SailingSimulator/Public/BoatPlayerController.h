// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SailingBoat_v2.h"
#include "BoatPlayerController.generated.h"

class UImage;
class UTexture2D;
class USceneComponent;
class UUserWidget;


UENUM(BlueprintType)
enum class EHandCursorState : uint8
{
    Neutral,
    Hover,
    Grabbing
};


UCLASS()
class SAILINGSIMULATOR_API ABoatPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ABoatPlayerController();
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UUserWidget> PauseWidgetClass;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	ASailingBoat_v2* BoatRef = nullptr;

    UPROPERTY()
    ASailingBoat_v2* SteeringBoatRef = nullptr;

    UPROPERTY()
    UUserWidget* PauseWidget = nullptr;

    bool bIsSteeringWheelDragging = false;
    bool bSteeringInteractionMode = false;

    bool bIsPaused = false;

    void ToggleSteeringInteractionMode();
    void TogglePause();

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

    UPROPERTY(EditDefaultsOnly, Category = "Interaction|Cursor")
    TSubclassOf<UUserWidget> HandCursorWidgetClass;

    UPROPERTY(Transient)
    TObjectPtr<UUserWidget> HandCursorWidget = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UImage> HandIconImage = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Interaction|Cursor")
    TObjectPtr<UTexture2D> CursorDotTexture = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Interaction|Cursor")
    TObjectPtr<UTexture2D> CursorOpenHandTexture = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Interaction|Cursor")
    TObjectPtr<UTexture2D> CursorClosedHandTexture = nullptr;

    // Aktualny stan kursora
    EHandCursorState HandCursorState = EHandCursorState::Neutral;

    void UpdateHandCursor();
    void SetHandCursorState(EHandCursorState NewState);
};
