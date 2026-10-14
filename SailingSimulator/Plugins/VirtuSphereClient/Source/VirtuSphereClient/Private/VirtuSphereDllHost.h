#pragma once

#include "hostfxr.h"
#include "coreclr_delegates.h"
#include <map>
#include <vector>
#include <functional>

#pragma pack(push, 1)
extern "C" struct SpherePoseEventStruct
{
	int64_t timestamp;

	float velocity;
	float direction;

	float targetVelocityVectorX;
	float targetVelocityVectorY;
	float targetVelocityVectorZ;
	float actualVelocityVectorX;
	float actualVelocityVectorY;
	float actualVelocityVectorZ;
};

extern "C" struct ControllerStateEventStruct
{
	int64_t timestamp;

	int controllerId;
	int statusRegister;
	int errorRegister;

	float electronicVoltage;
	float powerVoltage;
	float powerStageTemperature;
};

extern "C" struct MotorStateEventStruct
{
	int64_t timestamp;

	int controllerId;

	int8_t motorFlags;
	int hallPosition;
	int encoderPosition;
	float motorTargetVelocity;
	float motorActualVelocity;
	float motorVoltage;
	float motorTargetCurrent;
	float motorActualCurrent;
};
#pragma pack(pop)

enum VirtuSphereEventType
{
	VSE_SpherePose = 0,
	VSE_ControllerState = 1,
	VSE_MotorState = 2
};

enum VirtuSphereClientMode
{
	VSCM_READ_PARAMETERS = 0,
	VSCM_CONTROL_MOTORS = 1
};

enum VirtuSphereConnectionState
{
	VSCS_NULL = 0,
	VSCS_CONNECTING = 1,
	VSCS_CONNECTED = 2,
	VSCS_DISCONNECTED = 3
};

typedef void(__cdecl consoleLogCallback_fn)(void* context, int32_t mode, const char* value);
typedef void (__cdecl connectionStateChangeCallback_fn)(void* context, int32_t state);
typedef void (__cdecl spherePoseCallback_fn)(void* context, SpherePoseEventStruct evt);
typedef void(__cdecl controllerStateCallback_fn)(void* context, ControllerStateEventStruct evt);
typedef void(__cdecl motorStateCallback_fn)(void* context, MotorStateEventStruct evt);

typedef bool (CORECLR_DELEGATE_CALLTYPE* initialize_fn)(int clientMode, const char* clientName, const char* deviceUUID);
typedef void (CORECLR_DELEGATE_CALLTYPE* setConsoleLogCallback_fn)(consoleLogCallback_fn callback, void* callbackContext);
typedef void (CORECLR_DELEGATE_CALLTYPE* setConnectionStateChangeCallback_fn)(connectionStateChangeCallback_fn callback, void* callbackContext);
typedef void (CORECLR_DELEGATE_CALLTYPE* setSpherePoseCallback_fn)(spherePoseCallback_fn callback, void* callbackContext);
typedef void (CORECLR_DELEGATE_CALLTYPE* setControllerStateCallback_fn)(controllerStateCallback_fn callback, void* callbackContext);
typedef void (CORECLR_DELEGATE_CALLTYPE* setMotorStateCallback_fn)(motorStateCallback_fn callback, void* callbackContext);
typedef void (CORECLR_DELEGATE_CALLTYPE* connect_fn)(void* hostString, int32_t port);
typedef void (CORECLR_DELEGATE_CALLTYPE* disconnect_fn)();
typedef bool (CORECLR_DELEGATE_CALLTYPE* isConnected_fn)();
typedef float (CORECLR_DELEGATE_CALLTYPE* getCurrentPing_fn)();
typedef void (CORECLR_DELEGATE_CALLTYPE* requestSpherePoseUpdates_fn)(int32_t sendRate);
typedef void (CORECLR_DELEGATE_CALLTYPE* requestControllerStateUpdates_fn)(int32_t sendRate);
typedef void (CORECLR_DELEGATE_CALLTYPE* requestMotorStateUpdates_fn)(int32_t sendRate);
typedef void (CORECLR_DELEGATE_CALLTYPE* setSpherePose_fn)(float velocity, float direction);
typedef void (CORECLR_DELEGATE_CALLTYPE* setSphereVector_fn)(float vx, float vy, float wz);
typedef void (CORECLR_DELEGATE_CALLTYPE* setMotorPower_fn)(uint8_t enabled);
typedef void (CORECLR_DELEGATE_CALLTYPE* onUpdate_fn)();


extern "C" void __cdecl consoleLog_cb(void* context, int32_t mode, const char* value);
extern "C" void __cdecl connectionState_cb(void* context, int32_t state);
extern "C" void __cdecl spherePose_cb(void* context, SpherePoseEventStruct evt);
extern "C" void __cdecl controllerState_cb(void* context, ControllerStateEventStruct evt);
extern "C" void __cdecl motorState_cb(void* context, MotorStateEventStruct evt);

class VirtuSphereDllHost
{
private:

	hostfxr_handle hostfxr_cxt;
	bool initialized;

	std::vector<std::function<void(int)>*> connectionStateChangeListeners;
	std::map<VirtuSphereEventType, std::vector<std::function<void(void*)>*>> eventListeners;

	bool LoadHostfxr();
	bool LoadVirtuSphereClientDll();
	bool InitVirtuSphereClient(const char* clientName, const char* deviceUUID);

	//Hostfxr functions
	hostfxr_initialize_for_runtime_config_fn init_fptr;
	hostfxr_get_runtime_delegate_fn get_delegate_fptr;
	hostfxr_set_error_writer_fn set_error_writer_fptr;
	hostfxr_get_runtime_properties_fn get_runtime_properties_fptr;
	hostfxr_get_runtime_property_value_fn get_runtime_property_value_fptr;
	hostfxr_set_runtime_property_value_fn set_runtime_property_value_fptr;
	hostfxr_close_fn close_fptr;

	load_assembly_fn load_assembly;
	load_assembly_and_get_function_pointer_fn load_assembly_and_get_function_pointer;

	//VirtuSphereClient dll functions
	initialize_fn vsInitialize_fptr;
	setConsoleLogCallback_fn vsSetConsoleLogCallback_fptr;
	setConnectionStateChangeCallback_fn vsSetConnectionStateChangeCallback_fptr;
	setSpherePoseCallback_fn vsSetSpherePoseCallback_fptr;
	setControllerStateCallback_fn vsSetControllerStateCallback_fptr;
	setMotorStateCallback_fn vsSetMotorStateCallback_fptr;
	connect_fn vsConnect_fptr;
	disconnect_fn vsDisconnect_fptr;
	isConnected_fn vsIsConnected_fptr;
	getCurrentPing_fn vsGetCurrentPing_fptr;
	requestSpherePoseUpdates_fn vsRequestSpherePoseUpdates_fptr;
	requestControllerStateUpdates_fn vsRequestControllerStateUpdates_fptr;
	requestMotorStateUpdates_fn vsRequestMotorStateUpdates_fptr;
	setSpherePose_fn vsSetSpherePose_fptr;
	setSphereVector_fn vsSetSphereVector_fptr;
	setMotorPower_fn vsSetMotorPower_fptr;
	onUpdate_fn vsOnUpdate_fptr;

public:

	VirtuSphereDllHost(const char* clientName, const char* deviceUUID);
	~VirtuSphereDllHost();

	bool IsInitialized() { return initialized; }

	void OnConnectionStateChangeCallback(int32_t state);
	void OnSpherePoseCallback(SpherePoseEventStruct* evt);
	void OnControllerStateCallback(ControllerStateEventStruct* evt);
	void OnMotorStateCallback(MotorStateEventStruct* evt);

	void RegisterConnectionStateChangeListener(std::function<void(int)>* listener);
	void UnregisterConnectionStateChangeListener(std::function<void(int)>* listener);
	void RegisterEventListener(VirtuSphereEventType eventType, std::function<void(void*)>* listener);
	void UnregisterEventListener(std::function<void(void*)>* listener);

	void Connect(FString host = "127.0.0.1", int port = 4445) {
		if (!IsInitialized())
			return;
		vsConnect_fptr((void*)(const char_t*)*host, port);
	}

	void Disconnect() {
		if (!IsInitialized())
			return;
		vsDisconnect_fptr();
	}

	bool IsConnected() {
		if (!IsInitialized())
			return false;
		return vsIsConnected_fptr();
	}

	float GetCurrentPing() {
		if (!IsInitialized())
			return 9999.0f;
		return vsGetCurrentPing_fptr();
	}

	void RequestSpherePoseUpdates(int sendRate) {
		if (!IsInitialized())
			return;
		vsRequestSpherePoseUpdates_fptr(sendRate);
	}

	void RequestControllerStateUpdates(int sendRate) {
		if (!IsInitialized())
			return;
		vsRequestControllerStateUpdates_fptr(sendRate);
	}

	void RequestMotorStateUpdates(int sendRate) {
		if (!IsInitialized())
			return;
		vsRequestMotorStateUpdates_fptr(sendRate);
	}

	void SetSpherePose(float velocity, float direction) {
		if (!IsInitialized())
			return;
		vsSetSpherePose_fptr(velocity, direction);
	}

	void SetSphereVector(float vx, float vy, float wz) {
		if (!IsInitialized())
			return;
		vsSetSphereVector_fptr(vx, vy, wz);
	}

	void SetMotorPower(bool enabled) {
		if (!IsInitialized())
			return;
		vsSetMotorPower_fptr(enabled ? 1 : 0);
	}

	void OnUpdate() {
		if (!IsInitialized())
			return;
		vsOnUpdate_fptr();
	}
};