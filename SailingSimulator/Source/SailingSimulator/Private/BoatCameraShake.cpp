// Fill out your copyright notice in the Description page of Project Settings.


#include "BoatCameraShake.h"

UBoatCameraShake::UBoatCameraShake()
{
	// Duration time
	OscillationDuration = 10.0f;
    OscillationBlendInTime = 1.0f;
    OscillationBlendOutTime = 1.0f;

	// Roll
	RotOscillation.Roll.Amplitude = 20.0f;
    RotOscillation.Roll.Frequency = 1.0f;
    RotOscillation.Roll.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;

	// Pitch
	RotOscillation.Pitch.Amplitude = 10.0f;
    RotOscillation.Pitch.Frequency = 1.0f;
    RotOscillation.Pitch.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;

	// Smooth camera move
	LocOscillation.Z.Amplitude = 10.0f;
    LocOscillation.Z.Frequency = 1.0f;
    LocOscillation.Z.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;
}