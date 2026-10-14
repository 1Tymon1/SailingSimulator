// Fill out your copyright notice in the Description page of Project Settings.


#include "AVirtuSphereController.h"
#include "VirtuSphereCommon.h"
#include "VirtuSphereClient.h"
#include "VirtuSphereDllHost.h"

// Sets default values
AVirtuSphereController::AVirtuSphereController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FVirtuSphereClientModule& clientModule = FModuleManager::LoadModuleChecked<FVirtuSphereClientModule>("VirtuSphereClient");
	dllHost = clientModule.getDllHost();

	connectionStateChangeListener = [this](int state) {
		switch (state) {
		case VSCS_CONNECTED:
			this->OnConnected();
			break;
		case VSCS_DISCONNECTED:
			this->OnDisconnected();
			break;
		}
	};

	spherePoseEventListener = [this](void* evt) {
		SpherePoseEventStruct* e = (SpherePoseEventStruct*)evt;
		FSpherePoseEvent fe;
		fe.timestamp = e->timestamp;
		fe.velocity = e->velocity;
		fe.direction = e->direction;
		fe.targetVelocityVectorX = e->targetVelocityVectorX;
		fe.targetVelocityVectorY = e->targetVelocityVectorY;
		fe.targetVelocityVectorZ = e->targetVelocityVectorZ;
		fe.actualVelocityVectorX = e->actualVelocityVectorX;
		fe.actualVelocityVectorY = e->actualVelocityVectorY;
		fe.actualVelocityVectorZ = e->actualVelocityVectorZ;
		this->OnSpherePose(fe);
		};

	controllerStateEventListener = [this](void* evt) {
		ControllerStateEventStruct* e = (ControllerStateEventStruct*)evt;
		FControllerStateEvent fe;
		fe.timestamp = e->timestamp;
		fe.controllerId = e->controllerId;
		fe.statusRegister = e->statusRegister;
		fe.errorRegister = e->errorRegister;
		fe.electronicVoltage = e->electronicVoltage;
		fe.powerVoltage = e->powerVoltage;
		fe.powerStageTemperature = e->powerStageTemperature;
		this->OnControllerState(fe);
		};

	motorStateEventListener = [this](void* evt) {
		MotorStateEventStruct* e = (MotorStateEventStruct*)evt;
		FMotorStateEvent fe;
		fe.timestamp = e->timestamp;
		fe.controllerId = e->controllerId;
		fe.motorFlags = e->motorFlags;
		fe.hallPosition = e->hallPosition;
		fe.encoderPosition = e->encoderPosition;
		fe.motorTargetVelocity = e->motorTargetVelocity;
		fe.motorActualVelocity = e->motorActualVelocity;
		fe.motorVoltage = e->motorVoltage;
		fe.motorTargetCurrent = e->motorTargetCurrent;
		fe.motorActualCurrent = e->motorActualCurrent;
		this->OnMotorState(fe);
		};
}

// Called when the game starts or when spawned
void AVirtuSphereController::BeginPlay()
{
	Super::BeginPlay();
	dllHost->RegisterConnectionStateChangeListener(&connectionStateChangeListener);
	dllHost->RegisterEventListener(VSE_SpherePose, &spherePoseEventListener);
	dllHost->RegisterEventListener(VSE_ControllerState, &controllerStateEventListener);
	dllHost->RegisterEventListener(VSE_MotorState, &motorStateEventListener);
}

void AVirtuSphereController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	dllHost->UnregisterEventListener(&motorStateEventListener);
	dllHost->UnregisterEventListener(&controllerStateEventListener);
	dllHost->UnregisterEventListener(&spherePoseEventListener);
	dllHost->UnregisterConnectionStateChangeListener(&connectionStateChangeListener);
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AVirtuSphereController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	dllHost->OnUpdate();
}

void AVirtuSphereController::Connect(FString host, int port)
{
	if (dllHost->IsConnected()) {
		UE_LOG(LogVirtuSphereClient, Error, TEXT("[VirtuSphereController] Already connected"));
		return;
	}

	dllHost->Connect(host, port);
}

void AVirtuSphereController::Disconnect()
{
	if (dllHost->IsConnected()) {
		dllHost->Disconnect();

		int n = 0;
		for (n = 0; n < 100; n++) {
			if (!dllHost->IsConnected())
				break;

			dllHost->OnUpdate();
			FPlatformProcess::Sleep(0.02f);
		}

		if (n >= 100)
			UE_LOG(LogVirtuSphereClient, Error, TEXT("[VirtuSphereController] Disconnect() timed out"));
	}
}

bool AVirtuSphereController::IsConnected()
{
	return dllHost->IsConnected();
}

float AVirtuSphereController::GetCurrentPing()
{
	return dllHost->GetCurrentPing();
}

void AVirtuSphereController::RequestSpherePoseUpdates(int sendRate)
{
	dllHost->RequestSpherePoseUpdates(sendRate);
}

void AVirtuSphereController::RequestControllerStateUpdates(int sendRate)
{
	dllHost->RequestControllerStateUpdates(sendRate);
}

void AVirtuSphereController::RequestMotorStateUpdates(int sendRate)
{
	dllHost->RequestMotorStateUpdates(sendRate);
}

void AVirtuSphereController::SetSpherePose(float velocity, float direction)
{
	dllHost->SetSpherePose(velocity, direction);
}

void AVirtuSphereController::SetSphereVector(float vx, float vy, float wz)
{
	dllHost->SetSphereVector(vx, vy, wz);
}

void AVirtuSphereController::SetMotorPower(bool enabled)
{
	dllHost->SetMotorPower(enabled);
}

void AVirtuSphereController::OnConnected_Implementation() {
	UE_LOG(LogVirtuSphereClient, Log, TEXT("[VirtuSphereController] OnConnected() C++"));
}

void AVirtuSphereController::OnDisconnected_Implementation() {}
void AVirtuSphereController::OnSpherePose_Implementation(FSpherePoseEvent event) {}
void AVirtuSphereController::OnControllerState_Implementation(FControllerStateEvent event) {}
void AVirtuSphereController::OnMotorState_Implementation(FMotorStateEvent event) {}