#include "BoatPlayerController.h"
#include "SailingBoat_v2.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"

ABoatPlayerController::ABoatPlayerController(){
	bShowMouseCursor = false;
    PrimaryActorTick.bCanEverTick = true;
}

void ABoatPlayerController::BeginPlay(){
	Super::BeginPlay();
    bShowMouseCursor = false;

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue,
			TEXT("BoatPlayerController: BeginPlay")
		);
	}

	{
		APawn* MyPawn = GetPawn();

		if (MyPawn){
			TArray<USceneComponent*> SceneComponents;
			MyPawn->GetComponents<USceneComponent>(SceneComponents);

			for (USceneComponent* Component : SceneComponents)
			{
				if (!Component)
				{
					continue;
				}

				if (Component->GetName().StartsWith(TEXT("CameraPivot")))
				{
					CameraPivot = Component;
					break;
				}
			}

			if (CameraPivot)
			{
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(
						-1,
						5.0f,
						FColor::Green,
						TEXT("BoatPlayerController: CameraPivot FOUND")
					);
				}
			}
			else
			{
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(
						-1,
						5.0f,
						FColor::Red,
						TEXT("BoatPlayerController: CameraPivot NOT FOUND")
					);
				}
			}
		}
	}


	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, [this]()
	{
		AActor* found = UGameplayStatics::GetActorOfClass(
			GetWorld(),
			ASailingBoat_v2::StaticClass()
		);

		if(found){
			BoatRef = Cast<ASailingBoat_v2>(found);
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("BOAT FOUNDED"));
			}

			APawn* MyPawn = GetPawn();
		}
		else{
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("ERROR: BOAT NOT FOUNDED"));
			}
		}
	}, 0.5f, false);

    if (!HandCursorWidgetClass)
    {
        if (GEngine) {
            GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("HandCursorWidgetClass is not assigned!"));
        }
        return;
    }

    HandCursorWidget = CreateWidget<UUserWidget>(this, HandCursorWidgetClass);

    if (!HandCursorWidget)
    {
        if (GEngine) {
            GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Failed to create HandCursorWidget!"));
        }
        return;
    }

    
    HandCursorWidget->AddToViewport(200);

    HandCursorWidget->SetPositionInViewport(
        FVector2D(0.0f, 0.0f)
    );

    HandCursorWidget->SetDesiredSizeInViewport(
        FVector2D(1920.0f, 1080.0f)
    );

    if (GEngine && GEngine->GameViewport)
    {
        FVector2D ViewportSize;

        GEngine->GameViewport->GetViewportSize(ViewportSize);

        HandCursorWidget->SetDesiredSizeInViewport(ViewportSize);
    }

    HandIconImage = Cast<UImage>(HandCursorWidget->GetWidgetFromName(TEXT("HandImage")));

    if (!HandIconImage)
    {
        if (GEngine) {
            GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Could not find Image named HandImage!"));
        }
        return;
    }

    SetHandCursorState(EHandCursorState::Neutral);
}

void ABoatPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(bIsPaused) return;

    UpdateBoatCameraMotion(DeltaTime);
    UpdateSteeringWheelDrag();
    UpdateHandCursor();
}

void ABoatPlayerController::SetupInputComponent(){
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ABoatPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABoatPlayerController::MoveRight);

	InputComponent->BindAxis("LookYaw", this, &ABoatPlayerController::LookYaw);
	InputComponent->BindAxis("LookPitch", this, &ABoatPlayerController::LookPitch);

	InputComponent->BindAxis("BoatForward", this, &ABoatPlayerController::BoatForward);
    InputComponent->BindAxis("BoatTurn", this, &ABoatPlayerController::BoatTurn);

    InputComponent->BindAction("GrabSteeringWheel", IE_Pressed, this, &ABoatPlayerController::BeginSteeringWheelDrag);
    InputComponent->BindAction("GrabSteeringWheel", IE_Released, this, &ABoatPlayerController::EndSteeringWheelDrag);

    InputComponent->BindKey(EKeys::E, IE_Pressed, this, &ABoatPlayerController::ToggleSteeringInteractionMode);

    FInputKeyBinding& PauseBinding = InputComponent->BindKey(EKeys::Q, IE_Pressed, this, &ABoatPlayerController::TogglePause);

    PauseBinding.bExecuteWhenPaused = true;
}

void ABoatPlayerController::MoveForward(float value){
	if(FMath::IsNearlyZero(value)) return;
	ACharacter* character = Cast<ACharacter>(GetPawn());
	if(!character) return;

	character->AddMovementInput(character->GetActorForwardVector(), value);
}

void ABoatPlayerController::MoveRight(float value){
	if(FMath::IsNearlyZero(value)) return;
	ACharacter* character = Cast<ACharacter>(GetPawn());
	if(!character) return;

	character->AddMovementInput(character->GetActorRightVector(), value);
}

void ABoatPlayerController::LookYaw(float Value)
{
    if (bSteeringInteractionMode)
    {
        return;
    }

    AddYawInput(Value);
}

void ABoatPlayerController::LookPitch(float Value)
{
    if (bSteeringInteractionMode)
    {
        return;
    }

    AddPitchInput(Value);
}

void ABoatPlayerController::BoatForward(float value){
	if(!BoatRef) return;
	BoatRef->SetThrottle(value);
}

void ABoatPlayerController::BoatTurn(float value){
	if(!BoatRef) return;
	BoatRef->SetSteering(value);
}


void ABoatPlayerController::BeginSteeringWheelDrag()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1, 3.0f, FColor::Yellow,
            TEXT("LMB pressed - BeginSteeringWheelDrag")
        );
    }

    FHitResult Hit;

    if (!GetHitResultUnderCursor(ECC_Visibility, true, Hit))
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(
                -1, 3.0f, FColor::Red,
                TEXT("No hit under cursor")
            );
        }
        return;
    }

    UPrimitiveComponent* HitComponent = Hit.GetComponent();
    AActor* HitActor = Hit.GetActor();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1, 5.0f, FColor::Cyan,
            FString::Printf(
                TEXT("Hit actor: %s | Component: %s"),
                *GetNameSafe(HitActor),
                *GetNameSafe(HitComponent)
            )
        );
    }

    ASailingBoat_v2* HitBoat = Cast<ASailingBoat_v2>(HitActor);

    if (!HitBoat)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(
                -1, 3.0f, FColor::Red,
                TEXT("Hit actor is not ASailingBoat_v2")
            );
        }
        return;
    }

    if (!HitComponent || HitComponent != HitBoat->SteeringWheelHitbox)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(
                -1, 3.0f, FColor::Red,
                FString::Printf(
                    TEXT("Wrong component. Expected: %s"),
                    *GetNameSafe(HitBoat->SteeringWheelHitbox)
                )
            );
        }
        return;
    }

    SteeringBoatRef = HitBoat;
    bIsSteeringWheelDragging = true;
    SetHandCursorState(EHandCursorState::Grabbing);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1, 3.0f, FColor::Green,
            TEXT("SUCCESS: Steering wheel grabbed!")
        );
    }
}

void ABoatPlayerController::EndSteeringWheelDrag()
{
    bIsSteeringWheelDragging = false;
    SteeringBoatRef = nullptr;
    SetHandCursorState(EHandCursorState::Neutral);
}

void ABoatPlayerController::UpdateSteeringWheelDrag()
{
    if (!bIsSteeringWheelDragging || !SteeringBoatRef)
    {
        return;
    }

    float MouseX = 0.0f;
    float MouseY = 0.0f;

    GetInputMouseDelta(MouseX, MouseY);

    if (FMath::IsNearlyZero(MouseX))
    {
        return;
    }

    const float NewAngle = SteeringBoatRef->GetSteeringWheelAngle() + MouseX * MouseSteeringSensitivity;

    SteeringBoatRef->SetSteeringWheelAngle(NewAngle);
}

void ABoatPlayerController::SetHandCursorState(EHandCursorState NewState)
{
    if (HandCursorState == NewState && HandIconImage)
    {
        return;
    }

    HandCursorState = NewState;

    if (!HandIconImage)
    {
        return;
    }

    UTexture2D* TextureToUse = CursorDotTexture;

    switch (HandCursorState)
    {
        case EHandCursorState::Hover:
            TextureToUse = CursorOpenHandTexture;
            break;

        case EHandCursorState::Grabbing:
            TextureToUse = CursorClosedHandTexture;
            break;

        case EHandCursorState::Neutral:
        default:
            TextureToUse = CursorDotTexture;
            break;
    }

    if (TextureToUse)
    {
        HandIconImage->SetBrushFromTexture(TextureToUse);
    }
}

void ABoatPlayerController::UpdateHandCursor()
{
    if (!HandCursorWidget || !HandIconImage)
    {
        return;
    }

    if (!bSteeringInteractionMode && !bIsPaused)
    {
        HandCursorWidget->SetVisibility(ESlateVisibility::Collapsed);
        return;
    }

    HandCursorWidget->SetVisibility(ESlateVisibility::HitTestInvisible);

    if (bIsSteeringWheelDragging && SteeringBoatRef)
    {
        SetHandCursorState(EHandCursorState::Grabbing);
    }

    else if (bIsPaused)
    {
        SetHandCursorState(EHandCursorState::Neutral);
    }
    else
    {
        FHitResult Hit;
        bool bIsHoveringSteeringWheel = false;

        if (GetHitResultUnderCursor(ECC_Visibility, true, Hit))
        {
            ASailingBoat_v2* HitBoat = Cast<ASailingBoat_v2>(Hit.GetActor());

            if (HitBoat &&
                Hit.GetComponent() == HitBoat->SteeringWheelHitbox)
            {
                bIsHoveringSteeringWheel = true;
            }
        }

        SetHandCursorState(bIsHoveringSteeringWheel ? EHandCursorState::Hover : EHandCursorState::Neutral);
    }

    float MouseX = 0.0f;
    float MouseY = 0.0f;

    if (GetMousePosition(MouseX, MouseY))
    {
        HandCursorWidget->SetPositionInViewport(FVector2D(MouseX, MouseY), false);
    }
}


void ABoatPlayerController::ToggleSteeringInteractionMode()
{
    bSteeringInteractionMode = !bSteeringInteractionMode;

    if (bSteeringInteractionMode)
    {
        bShowMouseCursor = true;

        FInputModeGameAndUI InputMode;
        InputMode.SetHideCursorDuringCapture(false);
        InputMode.SetLockMouseToViewportBehavior(
            EMouseLockMode::DoNotLock
        );

        SetInputMode(InputMode);
    }
    else
    {
        EndSteeringWheelDrag();

        bShowMouseCursor = false;

        FInputModeGameOnly InputMode;
        SetInputMode(InputMode);
    }
}

void ABoatPlayerController::TogglePause()
{
    if (!bIsPaused)
    {
        // Stop simulation
        bIsPaused = true;
        EndSteeringWheelDrag();

        if (!PauseWidget && PauseWidgetClass)
        {
            PauseWidget = CreateWidget<UUserWidget>(
                this,
                PauseWidgetClass
            );
        }

        if (PauseWidget)
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(
                    -1, 3.0f, FColor::Green,
                    TEXT("FAIL: PauseWidgetClass is assigned!")
                );
            }
            PauseWidget->AddToViewport(100);
        }
        else
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(
                    -1, 3.0f, FColor::Red,
                    TEXT("FAIL: PauseWidgetClass is not assigned!")
                );
            }
        }

        bShowMouseCursor = true;

        FInputModeGameAndUI InputMode;
        InputMode.SetHideCursorDuringCapture(false);
        InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        SetInputMode(InputMode);

        UGameplayStatics::SetGamePaused(GetWorld(), true);
    }
    else
    {
        UGameplayStatics::SetGamePaused(GetWorld(), false);
        bIsPaused = false;

        if (PauseWidget)
        {
            PauseWidget->RemoveFromParent();
        }

        if (bSteeringInteractionMode)
        {
            bShowMouseCursor = true;

            FInputModeGameAndUI InputMode;
            InputMode.SetHideCursorDuringCapture(false);
            InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
            SetInputMode(InputMode);
        }
        else
        {
            bShowMouseCursor = false;

            FInputModeGameOnly InputMode;
            SetInputMode(InputMode);
        }
    }
}


void ABoatPlayerController::UpdateBoatCameraMotion(float DeltaTime)
{
    if (!BoatRef || !BoatRef->BuoyancyComponent || !CameraPivot)
    {
        return;
    }

    const FTransform BoatTransform = BoatRef->GetActorTransform();
    const FVector BoatForward = BoatTransform.GetUnitAxis(EAxis::X);
    const FVector BoatRight = BoatTransform.GetUnitAxis(EAxis::Y);
    const FVector BoatUp = BoatTransform.GetUnitAxis(EAxis::Z);

    // Boat boarders
    float MinPontoonX = TNumericLimits<float>::Max();
    float MaxPontoonX = TNumericLimits<float>::Lowest();
    float MinPontoonY = TNumericLimits<float>::Max();
    float MaxPontoonY = TNumericLimits<float>::Lowest();

    bool bFoundPontoons = false;

    for (const FSphericalPontoon& Pontoon :
         BoatRef->BuoyancyComponent->BuoyancyData.Pontoons)
    {
        const FVector LocalPosition = Pontoon.RelativeLocation;

        MinPontoonX = FMath::Min(MinPontoonX, LocalPosition.X);
        MaxPontoonX = FMath::Max(MaxPontoonX, LocalPosition.X);
        MinPontoonY = FMath::Min(MinPontoonY, LocalPosition.Y);
        MaxPontoonY = FMath::Max(MaxPontoonY, LocalPosition.Y);

        bFoundPontoons = true;
    }

    if (!bFoundPontoons) return;


    // =========================================================
    // 3. POZYCJA CAMERA PIVOT W PRZESTRZENI £ODZI
    //
    // Dziêki temu wiemy:
    //
    // X < 0  = rufa
    // X = 0  = œrodek
    // X > 0  = dziób
    //
    // Y < 0  = lewa burta
    // Y = 0  = œrodek
    // Y > 0  = prawa burta
    // =========================================================

    const FVector CameraWorldLocation = CameraPivot->GetComponentLocation();
    const FVector CameraLocalLocation = BoatTransform.InverseTransformPosition(CameraWorldLocation);

    const float PontoonCenterX = (MinPontoonX + MaxPontoonX) * 0.5f;
    const float PontoonCenterY = (MinPontoonY + MaxPontoonY) * 0.5f;


    
    // =========================================================
    // 5. PO£O¯ENIE KAMERY WZGLÊDEM ŒRODKA £ODZI
    //
    // Zakres:
    //
    // X:
    // -1 = rufa
    //  0 = œrodek
    // +1 = dziób
    //
    // Y:
    // -1 = lewa burta
    //  0 = œrodek
    // +1 = prawa burta
    // =========================================================

    const float HalfBoatLength = (MaxPontoonX - MinPontoonX) * 0.5f;
    const float HalfBoatWidth = (MaxPontoonY - MinPontoonY) * 0.5f;

    float CameraLongitudinalFactor = 0.0f;
    float CameraLateralFactor = 0.0f;

    if (!FMath::IsNearlyZero(HalfBoatLength))
    {
        CameraLongitudinalFactor = (CameraLocalLocation.X - PontoonCenterX) / HalfBoatLength;
    }

    if (!FMath::IsNearlyZero(HalfBoatWidth))
    {
        CameraLateralFactor = (CameraLocalLocation.Y - PontoonCenterY) / HalfBoatWidth;
    }

    CameraLongitudinalFactor = FMath::Clamp(CameraLongitudinalFactor, -1.0f, 1.0f);
    CameraLateralFactor = FMath::Clamp(CameraLateralFactor, -1.0f, 1.0f);


    // =========================================================
    // 6. SI£A EFEKTU ZALE¯NA OD POZYCJI KAMERY
    //
    // Œrodek -> prawie zero
    // Brzeg -> pe³ny efekt
    //
    // Power 1.5 powoduje, ¿e przy œrodku efekt jest bardzo
    // delikatny, a mocniej zaczyna dzia³aæ bli¿ej krawêdzi.
    // =========================================================

    const float CameraLateralStrength =FMath::Pow(FMath::Abs(CameraLateralFactor), 0.5f);
    const float CameraLongitudinalStrength = FMath::Pow(FMath::Abs(CameraLongitudinalFactor), 0.5f);

    const FRotator CurrentControlRotation = GetControlRotation();
    const FRotationMatrix CameraRotationMatrix(CurrentControlRotation);

    const FVector CameraForward = CameraRotationMatrix.GetUnitAxis(EAxis::X);
    const FVector CameraRight = CameraRotationMatrix.GetUnitAxis(EAxis::Y);
    const FVector CameraUp = CameraRotationMatrix.GetUnitAxis(EAxis::Z);


    const FVector BoatUpInCameraSpace(
        FVector::DotProduct(BoatUp, CameraForward),
        FVector::DotProduct(BoatUp, CameraRight),
        FVector::DotProduct(BoatUp, CameraUp)
    );

    const float BaseCameraRoll =FMath::RadiansToDegrees(FMath::Atan2(BoatUpInCameraSpace.Y, BoatUpInCameraSpace.Z));
    const float BaseCameraPitch =-FMath::RadiansToDegrees(FMath::Atan2(BoatUpInCameraSpace.X, BoatUpInCameraSpace.Z));


    const float PositionDependentRoll = BaseCameraRoll * CameraLateralStrength;
    const float PositionDependentPitch = BaseCameraPitch * CameraLongitudinalStrength;

    const float MaxCameraRoll = 8.0f;
    const float MaxCameraPitch = 5.0f;

    const float TargetCameraRoll = FMath::Clamp(PositionDependentRoll,-MaxCameraRoll,MaxCameraRoll);
    const float TargetCameraPitch = FMath::Clamp(PositionDependentPitch, -MaxCameraPitch, MaxCameraPitch);

    const float CameraInterpSpeed = 5.0f;

    CameraBoatRoll =
        FMath::FInterpTo(
            CameraBoatRoll,
            TargetCameraRoll,
            DeltaTime,
            CameraInterpSpeed
        );

    CameraBoatPitch =
        FMath::FInterpTo(
            CameraBoatPitch,
            TargetCameraPitch,
            DeltaTime,
            CameraInterpSpeed
        );

    FRotator FinalRotation = CurrentControlRotation;

    FinalRotation.Pitch += CameraBoatPitch;

    FinalRotation.Roll += CameraBoatRoll;

    CameraPivot->SetWorldRotation(FinalRotation);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            100,
            0.0f,
            FColor::Yellow,
            FString::Printf(
                TEXT(
                    "CamLocal X: %.1f Y: %.1f | "
                    "LongFactor: %.2f LatFactor: %.2f | "
                    "LongStrength: %.2f LatStrength: %.2f | "
                    "Target P: %.2f R: %.2f | "
                    "Final P: %.2f R: %.2f"
                ),
                CameraLocalLocation.X,
                CameraLocalLocation.Y,
                CameraLongitudinalFactor,
                CameraLateralFactor,
                CameraLongitudinalStrength,
                CameraLateralStrength,
                TargetCameraPitch,
                TargetCameraRoll,
                CameraBoatPitch,
                CameraBoatRoll
            )
        );
    }
}