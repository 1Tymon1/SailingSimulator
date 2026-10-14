#pragma once

#include "VirtuSphereClientStructs.generated.h"

USTRUCT(BlueprintType)
struct FSpherePoseEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int64 timestamp = 0;				//Unix timestamp in microseconds

	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float velocity = 0.0f;				//[m/s]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float direction = 0.0f;				//[deg]

	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float targetVelocityVectorX = 0.0f;	//[m/s]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float targetVelocityVectorY = 0.0f;	//[m/s]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float targetVelocityVectorZ = 0.0f;	//[rad/s]

	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float actualVelocityVectorX = 0.0f;	//[m/s]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float actualVelocityVectorY = 0.0f;	//[m/s]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float actualVelocityVectorZ = 0.0f;	//[rad/s]
};

USTRUCT(BlueprintType)
struct FControllerStateEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int64 timestamp = 0;				//Unix timestamp in microseconds

	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int controllerId = 0;
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int statusRegister = 0;
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int errorRegister = 0;

	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float electronicVoltage = 0.0f;		//[V]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float powerVoltage = 0.0f;			//[V]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float powerStageTemperature = 0.0f;	//[deg C]
};

USTRUCT(BlueprintType)
struct FMotorStateEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int64 timestamp = 0;				//Unix timestamp in microseconds

	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int controllerId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int motorFlags = 0;
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int hallPosition = 0;				//[counts]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	int encoderPosition = 0;			//[counts]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float motorTargetVelocity = 0.0f;	//[RPM]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float motorActualVelocity = 0.0f;	//[RPM]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float motorVoltage = 0.0f;			//[V]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float motorTargetCurrent = 0.0f;	//[A]
	UPROPERTY(BlueprintReadWrite, Category = "VirtuSphereClient | Struct Variables")
	float motorActualCurrent = 0.0f;	//[A]
};