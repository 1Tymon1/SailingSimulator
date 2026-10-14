// Fill out your copyright notice in the Description page of Project Settings.


#include "BoatPlayerController.h"
#include "SailingBoat_v2.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"

ABoatPlayerController::ABoatPlayerController(){
	bShowMouseCursor = false;
}

void ABoatPlayerController::BeginPlay(){
	Super::BeginPlay();
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
			// if(MyPawn){
			// 	FVector BoatLocation = BoatRef->GetActorLocation();
			// 	FVector SpawnOffset = FVector(0.0f, -20.0f, 100.0f);
			// 	MyPawn->SetActorLocation(BoatLocation + SpawnOffset);

			// 	MyPawn->AttachToActor(BoatRef, FAttachmentTransformRules::KeepWorldTransform);
			// 	MyPawn->AttachToComponent(BoatRef->BoatMesh, FAttachmentTransformRules(
			// 		EAttachmentRule::KeepWorld,
			// 		EAttachmentRule::KeepWorld,
			// 		EAttachmentRule::KeepWorld,
			// 		true
			// 	));
			// }
		}
		else{
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("ERROR: BOAT NOT FOUNDED"));
			}
		}
	}, 0.5f, false);
	
    // bShowMouseCursor = false;

    // FInputModeGameAndUI InputMode;
    // InputMode.SetHideCursorDuringCapture(false);
    // InputMode.SetLockMouseToViewportBehavior(
    //     EMouseLockMode::DoNotLock
    // );

    // SetInputMode(InputMode);
}

void ABoatPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateBoatCameraMotion(DeltaTime);
    UpdateSteeringWheelDrag();
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

    if (!GetHitResultUnderCursor(
        ECC_Visibility,
        true,
        Hit))
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

    ASailingBoat_v2* HitBoat =
        Cast<ASailingBoat_v2>(HitActor);

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

    if (!HitComponent ||
        HitComponent != HitBoat->SteeringWheelHitbox)
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

    const float NewAngle =
        SteeringBoatRef->GetSteeringWheelAngle()
        + MouseX * MouseSteeringSensitivity;

    SteeringBoatRef->SetSteeringWheelAngle(NewAngle);
}

void ABoatPlayerController::ToggleSteeringInteractionMode()
{
    bSteeringInteractionMode = !bSteeringInteractionMode;

    if (bSteeringInteractionMode)
    {
        // Tryb obs≥ugi ko≥a sterniczego
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
        // Normalne sterowanie kamerπ
        EndSteeringWheelDrag();

        bShowMouseCursor = false;

        FInputModeGameOnly InputMode;
        SetInputMode(InputMode);
    }
}

void ABoatPlayerController::UpdateBoatCameraMotion(float DeltaTime)
{
    if (!BoatRef ||
        !BoatRef->BuoyancyComponent ||
        !CameraPivot)
    {
        return;
    }

    // =========================================================
    // 1. TRANSFORM £ODZI
    //
    // Uøywamy ActorTransform, poniewaø Twoje pontony sπ
    // liczone wzglÍdem ActorTransform w DrawPontoons().
    // =========================================================

    const FTransform BoatTransform =
        BoatRef->GetActorTransform();

    const FVector BoatForward =
        BoatTransform.GetUnitAxis(EAxis::X);

    const FVector BoatRight =
        BoatTransform.GetUnitAxis(EAxis::Y);

    const FVector BoatUp =
        BoatTransform.GetUnitAxis(EAxis::Z);


    // =========================================================
    // 2. ZNAJDè GRANICE £ODZI NA PODSTAWIE PONTON”W
    //
    // X = przÛd / ty≥
    // Y = lewa / prawa burta
    // =========================================================

    float MinPontoonX = TNumericLimits<float>::Max();
    float MaxPontoonX = TNumericLimits<float>::Lowest();

    float MinPontoonY = TNumericLimits<float>::Max();
    float MaxPontoonY = TNumericLimits<float>::Lowest();

    bool bFoundPontoons = false;

    for (const FSphericalPontoon& Pontoon :
         BoatRef->BuoyancyComponent->BuoyancyData.Pontoons)
    {
        const FVector LocalPosition =
            Pontoon.RelativeLocation;

        MinPontoonX =
            FMath::Min(
                MinPontoonX,
                LocalPosition.X
            );

        MaxPontoonX =
            FMath::Max(
                MaxPontoonX,
                LocalPosition.X
            );

        MinPontoonY =
            FMath::Min(
                MinPontoonY,
                LocalPosition.Y
            );

        MaxPontoonY =
            FMath::Max(
                MaxPontoonY,
                LocalPosition.Y
            );

        bFoundPontoons = true;
    }

    if (!bFoundPontoons)
    {
        return;
    }


    // =========================================================
    // 3. POZYCJA CAMERA PIVOT W PRZESTRZENI £ODZI
    //
    // DziÍki temu wiemy:
    //
    // X < 0  = rufa
    // X = 0  = úrodek
    // X > 0  = dziÛb
    //
    // Y < 0  = lewa burta
    // Y = 0  = úrodek
    // Y > 0  = prawa burta
    // =========================================================

    const FVector CameraWorldLocation =
        CameraPivot->GetComponentLocation();

    const FVector CameraLocalLocation =
        BoatTransform.InverseTransformPosition(
            CameraWorldLocation
        );


    // =========================================================
    // 4. åRODEK OBSZARU PONTON”W
    // =========================================================

    const float PontoonCenterX =
        (MinPontoonX + MaxPontoonX) * 0.5f;

    const float PontoonCenterY =
        (MinPontoonY + MaxPontoonY) * 0.5f;


    // =========================================================
    // 5. PO£OØENIE KAMERY WZGL DEM åRODKA £ODZI
    //
    // Zakres:
    //
    // X:
    // -1 = rufa
    //  0 = úrodek
    // +1 = dziÛb
    //
    // Y:
    // -1 = lewa burta
    //  0 = úrodek
    // +1 = prawa burta
    // =========================================================

    const float HalfBoatLength =
        (MaxPontoonX - MinPontoonX) * 0.5f;

    const float HalfBoatWidth =
        (MaxPontoonY - MinPontoonY) * 0.5f;

    float CameraLongitudinalFactor = 0.0f;
    float CameraLateralFactor = 0.0f;

    if (!FMath::IsNearlyZero(HalfBoatLength))
    {
        CameraLongitudinalFactor =
            (CameraLocalLocation.X - PontoonCenterX)
            / HalfBoatLength;
    }

    if (!FMath::IsNearlyZero(HalfBoatWidth))
    {
        CameraLateralFactor =
            (CameraLocalLocation.Y - PontoonCenterY)
            / HalfBoatWidth;
    }

    CameraLongitudinalFactor =
        FMath::Clamp(
            CameraLongitudinalFactor,
            -1.0f,
            1.0f
        );

    CameraLateralFactor =
        FMath::Clamp(
            CameraLateralFactor,
            -1.0f,
            1.0f
        );


    // =========================================================
    // 6. SI£A EFEKTU ZALEØNA OD POZYCJI KAMERY
    //
    // årodek -> prawie zero
    // Brzeg -> pe≥ny efekt
    //
    // Power 1.5 powoduje, øe przy úrodku efekt jest bardzo
    // delikatny, a mocniej zaczyna dzia≥aÊ bliøej krawÍdzi.
    // =========================================================

    const float CameraLateralStrength =
        FMath::Pow(
            FMath::Abs(CameraLateralFactor),
            0.5f
        );

    const float CameraLongitudinalStrength =
        FMath::Pow(
            FMath::Abs(CameraLongitudinalFactor),
            0.5f
        );


    // =========================================================
    // 7. CONTROL ROTATION
    //
    // To jest normalne sterowanie kamerπ myszkπ.
    // =========================================================

    const FRotator CurrentControlRotation =
        GetControlRotation();


    // =========================================================
    // 8. OSIE KAMERY
    //
    // DziÍki temu przechy≥ ≥odzi jest interpretowany wzglÍdem
    // tego, gdzie aktualnie patrzy gracz.
    // =========================================================

    const FRotationMatrix CameraRotationMatrix(
        CurrentControlRotation
    );

    const FVector CameraForward =
        CameraRotationMatrix.GetUnitAxis(EAxis::X);

    const FVector CameraRight =
        CameraRotationMatrix.GetUnitAxis(EAxis::Y);

    const FVector CameraUp =
        CameraRotationMatrix.GetUnitAxis(EAxis::Z);


    // =========================================================
    // 9. G”RA £ODZI W PRZESTRZENI KAMERY
    //
    // To jest najwaøniejsza czÍúÊ.
    //
    // Nie pytamy:
    //
    // "ile stopni ma Roll ≥odzi?"
    //
    // tylko:
    //
    // "w ktÛrπ stronÍ przechyla siÍ ≥Ûdü wzglÍdem tego,
    //  w ktÛrπ stronÍ patrzy gracz?"
    // =========================================================

    const FVector BoatUpInCameraSpace(
        FVector::DotProduct(
            BoatUp,
            CameraForward
        ),

        FVector::DotProduct(
            BoatUp,
            CameraRight
        ),

        FVector::DotProduct(
            BoatUp,
            CameraUp
        )
    );


    // =========================================================
    // 10. BAZOWY ROLL KAMERY
    //
    // Roll = przechylenie lewo/prawo.
    //
    // CameraRight odpowiada za boczne wychylenie.
    // =========================================================

    const float BaseCameraRoll =
        FMath::RadiansToDegrees(
            FMath::Atan2(
                BoatUpInCameraSpace.Y,
                BoatUpInCameraSpace.Z
            )
        );


    // =========================================================
    // 11. BAZOWY PITCH KAMERY
    //
    // Pitch = gÛra/dÛ≥.
    // =========================================================

    const float BaseCameraPitch =
        -FMath::RadiansToDegrees(
            FMath::Atan2(
                BoatUpInCameraSpace.X,
                BoatUpInCameraSpace.Z
            )
        );


    // =========================================================
    // 12. WP£YW POZYCJI KAMERY
    //
    // ROLL:
    //
    // úrodek szerokoúci ≥odzi -> 0
    // burta -> pe≥ny efekt
    //
    // PITCH:
    //
    // úrodek d≥ugoúci -> 0
    // dziÛb/rufa -> pe≥ny efekt
    // =========================================================

    const float PositionDependentRoll =
        BaseCameraRoll *
        CameraLateralStrength;

    const float PositionDependentPitch =
        BaseCameraPitch *
        CameraLongitudinalStrength;


    // =========================================================
    // 13. MAKSYMALNY EFEKT
    //
    // Tutaj moøesz pÛüniej stroiÊ feeling kamery.
    // =========================================================

    const float MaxCameraRoll = 8.0f;
    const float MaxCameraPitch = 5.0f;

    const float TargetCameraRoll =
        FMath::Clamp(
            PositionDependentRoll,
            -MaxCameraRoll,
            MaxCameraRoll
        );

    const float TargetCameraPitch =
        FMath::Clamp(
            PositionDependentPitch,
            -MaxCameraPitch,
            MaxCameraPitch
        );


    // =========================================================
    // 14. WYG£ADZENIE
    // =========================================================

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


    // =========================================================
    // 15. FINALNA ROTACJA
    //
    // ControlRotation = mysz
    // CameraBoatPitch = ruch ≥odzi gÛra/dÛ≥
    // CameraBoatRoll  = ruch ≥odzi lewo/prawo
    // =========================================================

    FRotator FinalRotation =
        CurrentControlRotation;

    FinalRotation.Pitch +=
        CameraBoatPitch;

    FinalRotation.Roll +=
        CameraBoatRoll;


    CameraPivot->SetWorldRotation(
        FinalRotation
    );


    // =========================================================
    // 16. DEBUG
    // =========================================================

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