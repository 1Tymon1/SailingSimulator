#include "VirtuSphereDllHost.h"
#include "nethost.h"
#include "CoreMinimal.h"
#include "Engine.h"
#include "Interfaces/IPluginManager.h"

#include "VirtuSphereCommon.h"

#include <Windows.h>

extern "C" void __cdecl consoleLog_cb(void* context, int32_t mode, const char* value)
{
    wchar_t msg[2048];
    size_t n;
    mbstowcs_s(&n, msg, 2048, value, 2047);

    if (mode == 0) {
        UE_LOG(LogVirtuSphereClient, Display, TEXT("[DOTNETVM] %s"), (const TCHAR*)msg);
    }
    else {
        UE_LOG(LogVirtuSphereClient, Display, TEXT("[DOTNETVM] %s\n"), (const TCHAR*)msg);
    }
}

extern "C" void __cdecl connectionState_cb(void* context, int32_t state)
{
    if (context != nullptr)
        ((VirtuSphereDllHost*)context)->OnConnectionStateChangeCallback(state);
}

extern "C" void __cdecl spherePose_cb(void* context, SpherePoseEventStruct evt)
{
    if (context != nullptr)
        ((VirtuSphereDllHost*)context)->OnSpherePoseCallback(&evt);
}

extern "C" void __cdecl controllerState_cb(void* context, ControllerStateEventStruct evt)
{
    if (context != nullptr)
        ((VirtuSphereDllHost*)context)->OnControllerStateCallback(&evt);
}

extern "C" void __cdecl motorState_cb(void* context, MotorStateEventStruct evt)
{
    if (context != nullptr)
        ((VirtuSphereDllHost*)context)->OnMotorStateCallback(&evt);
}

void _cdecl hostfxr_error_writer(const char_t* message)
{
    char msg[2048];
    size_t n;
    wcstombs_s(&n, msg, 2048, message, 2047);

    UE_LOG(LogVirtuSphereClient, Error, TEXT("DOTNET ERROR: %s\n"), (const TCHAR*)msg);
}

VirtuSphereDllHost::VirtuSphereDllHost(const char* clientName, const char* deviceUUID)
{
    hostfxr_cxt = nullptr;
    initialized = false;

    UE_LOG(LogVirtuSphereClient, Display, TEXT("Initializing VirtuSphereClientDLL for %hs:%hs"), clientName, deviceUUID);

    if (!LoadHostfxr()) {
        UE_LOG(LogVirtuSphereClient, Warning, TEXT("Failed to load hostfxr"));
        return;
    }

    if (!LoadVirtuSphereClientDll()) {
        UE_LOG(LogVirtuSphereClient, Error, TEXT("Failed to load VirtuSphereClient DLL"));
        return;
    }

    if (!InitVirtuSphereClient(clientName, deviceUUID)) {
        UE_LOG(LogVirtuSphereClient, Error, TEXT("Failed to initialize VirtuSphereClient"));
        return;
    }

    UE_LOG(LogVirtuSphereClient, Display, TEXT("VirtuSphereClient DLL loaded and initialized"));
    initialized = true;
}

VirtuSphereDllHost::~VirtuSphereDllHost()
{
    if (initialized)
    {
        close_fptr(hostfxr_cxt);
        hostfxr_cxt = nullptr;
        initialized = false;
    }
}

bool VirtuSphereDllHost::LoadHostfxr()
{
    char_t buffer[MAX_PATH];
    size_t buffer_size = sizeof(buffer) / sizeof(char_t);
    int rc = get_hostfxr_path(buffer, &buffer_size, nullptr);
    if (rc != 0) {
        UE_LOG(LogVirtuSphereClient, Warning, TEXT("Failed to get hostfxr path"));
        return false;
    }

    // Load hostfxr
    HMODULE lib = LoadLibraryW(buffer);
    if (lib == nullptr) {
        UE_LOG(LogVirtuSphereClient, Warning, TEXT("LoadLibraryW failed"));
        return false;
    }

    init_fptr = (hostfxr_initialize_for_runtime_config_fn)GetProcAddress(lib, "hostfxr_initialize_for_runtime_config");
    get_delegate_fptr = (hostfxr_get_runtime_delegate_fn)GetProcAddress(lib, "hostfxr_get_runtime_delegate");
    close_fptr = (hostfxr_close_fn)GetProcAddress(lib, "hostfxr_close");
    set_error_writer_fptr = (hostfxr_set_error_writer_fn)GetProcAddress(lib, "hostfxr_set_error_writer");
    get_runtime_properties_fptr = (hostfxr_get_runtime_properties_fn)GetProcAddress(lib, "hostfxr_get_runtime_properties");
    get_runtime_property_value_fptr = (hostfxr_get_runtime_property_value_fn)GetProcAddress(lib, "hostfxr_get_runtime_property_value");
    set_runtime_property_value_fptr = (hostfxr_set_runtime_property_value_fn)GetProcAddress(lib, "hostfxr_set_runtime_property_value");

    if (!init_fptr || !get_delegate_fptr || !close_fptr || !set_error_writer_fptr || !get_runtime_properties_fptr || !get_runtime_property_value_fptr || !set_runtime_property_value_fptr) {
        UE_LOG(LogVirtuSphereClient, Warning, TEXT("Failed to get dll procedures"));
        return false;
    }

    // Load .NET Core
    FString pluginPath = IPluginManager::Get().FindPlugin(TEXT("VirtuSphereClient"))->GetBaseDir();
    FString binariesPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(pluginPath, TEXT("/ThirdParty/VirtuSphereClient/")));
    FString configPath = FPaths::Combine(binariesPath, TEXT("VirtuSphereClientCore.runtimeconfig.json"));
    UE_LOG(LogVirtuSphereClient, Log, TEXT("hostfxr config path: %s"), *configPath);

    rc = init_fptr((const char_t*)(*configPath), nullptr, &hostfxr_cxt);
    if (rc != 0 || hostfxr_cxt == nullptr)
    {
        //std::cerr << "Init failed: " << std::hex << std::showbase << rc << std::endl;
        UE_LOG(LogVirtuSphereClient, Warning, TEXT("hostfxr init failed, error=%d"), rc);
        close_fptr(hostfxr_cxt);
        return false;
    }
    set_error_writer_fptr(&hostfxr_error_writer);

    //FString binariesPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()) + FString("Binaries/Win64/");
    set_runtime_property_value_fptr(hostfxr_cxt, L"PROBING_DIRECTORIES", (const char_t*)(*binariesPath));

    size_t count = 128;
    const char_t* keys[128];
    const char_t* values[128];
    rc |= get_runtime_properties_fptr(hostfxr_cxt, &count, keys, values);

    // Get the load assembly function pointer
    rc = get_delegate_fptr(hostfxr_cxt, hdt_load_assembly, (void**)&load_assembly);
    rc |= get_delegate_fptr(hostfxr_cxt, hdt_load_assembly_and_get_function_pointer, (void**)&load_assembly_and_get_function_pointer);

    bool result = ((rc == 0) && (load_assembly_and_get_function_pointer != nullptr));
    if (!result) {
        UE_LOG(LogVirtuSphereClient, Warning, TEXT("failed to get hostfxr delegates"));
    }

    return result;
}

bool VirtuSphereDllHost::LoadVirtuSphereClientDll()
{
    //FString assemblyPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()) + FString("Binaries/Win64/VirtuSphereClientCore.dll");
    FString pluginPath = IPluginManager::Get().FindPlugin(TEXT("VirtuSphereClient"))->GetBaseDir();
    FString assemblyPath = FPaths::ConvertRelativePathToFull(FPaths::Combine(pluginPath, TEXT("/ThirdParty/VirtuSphereClient/VirtuSphereClientCore.dll")));
    const char_t* dotnet_type = L"VirtuSphereClientCore.VirtuSphereStaticClient, VirtuSphereClientCore";
    
    int rc = load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"Initialize",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+InitializeDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsInitialize_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"SetConsoleLogCallback",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+SetConsoleLogCallbackDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsSetConsoleLogCallback_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"SetConnectionStateChangeCallback",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+SetConnectionStateChangeCallbackDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsSetConnectionStateChangeCallback_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"SetSpherePoseCallback",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+SetSpherePoseCallbackDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsSetSpherePoseCallback_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"SetControllerStateCallback",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+SetControllerStateCallbackDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsSetControllerStateCallback_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"SetMotorStateCallback",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+SetMotorStateCallbackDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsSetMotorStateCallback_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"Connect",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+ConnectDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsConnect_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"Disconnect",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+DisconnectDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsDisconnect_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"IsConnected",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+IsConnectedDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsIsConnected_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"GetCurrentPing",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+GetCurrentPingDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsGetCurrentPing_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"RequestSpherePoseUpdates",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+RequestSpherePoseUpdatesDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsRequestSpherePoseUpdates_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"RequestControllerStateUpdates",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+RequestControllerStateUpdatesDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsRequestControllerStateUpdates_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"RequestMotorStateUpdates",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+RequestMotorStateUpdatesDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsRequestMotorStateUpdates_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"SetSpherePose",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+SetSpherePoseDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsSetSpherePose_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"SetSphereVector",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+SetSphereVectorDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsSetSphereVector_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"SetMotorPower",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+SetMotorPowerDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsSetMotorPower_fptr);

    rc |= load_assembly_and_get_function_pointer(
        (const char_t*)(*assemblyPath),
        dotnet_type,
        L"OnUpdate",
        L"VirtuSphereClientCore.VirtuSphereStaticClient+OnUpdateDelegate, VirtuSphereClientCore",
        nullptr,
        (void**)&vsOnUpdate_fptr);

    bool notNull = (vsInitialize_fptr != nullptr) &&
        (vsSetConsoleLogCallback_fptr != nullptr) &&
        (vsSetConnectionStateChangeCallback_fptr != nullptr) &&
        (vsSetSpherePoseCallback_fptr != nullptr) &&
        (vsSetControllerStateCallback_fptr != nullptr) &&
        (vsSetMotorStateCallback_fptr != nullptr) &&
        (vsConnect_fptr != nullptr) &&
        (vsDisconnect_fptr != nullptr) &&
        (vsIsConnected_fptr != nullptr) &&
        (vsGetCurrentPing_fptr != nullptr) &&
        (vsRequestSpherePoseUpdates_fptr != nullptr) &&
        (vsRequestControllerStateUpdates_fptr != nullptr) &&
        (vsRequestMotorStateUpdates_fptr != nullptr) &&
        (vsSetSpherePose_fptr != nullptr) &&
        (vsSetMotorPower_fptr != nullptr) &&
        (vsOnUpdate_fptr != nullptr);

    return (rc == 0) && notNull;
}

bool VirtuSphereDllHost::InitVirtuSphereClient(const char* clientName, const char* deviceUUID) {
    vsSetConsoleLogCallback_fptr(consoleLog_cb, this);
    vsSetConnectionStateChangeCallback_fptr(connectionState_cb, this);
    vsSetSpherePoseCallback_fptr(spherePose_cb, this);
    vsSetControllerStateCallback_fptr(controllerState_cb, this);
    vsSetMotorStateCallback_fptr(motorState_cb, this);

    return vsInitialize_fptr(VSCM_CONTROL_MOTORS, clientName, deviceUUID);
}

void VirtuSphereDllHost::OnConnectionStateChangeCallback(int32_t state) {
    if ((state < VSCS_NULL) || (state > VSCS_DISCONNECTED))
        return;

    for (std::function<void(int)>* listener : connectionStateChangeListeners)
    {
        (*listener)(state);
    }
}

void VirtuSphereDllHost::OnSpherePoseCallback(SpherePoseEventStruct* evt) {
    if (evt == nullptr)
        return;

    if (!eventListeners.contains(VSE_SpherePose))
        return;

    std::vector<std::function<void(void*)>*>& listeners = eventListeners[VSE_SpherePose];
    for (std::function<void(void*)>* listener : listeners)
        (*listener)(evt);
}

void VirtuSphereDllHost::OnControllerStateCallback(ControllerStateEventStruct* evt) {
    if (evt == nullptr)
        return;

    if (!eventListeners.contains(VSE_ControllerState))
        return;

    std::vector<std::function<void(void*)>*>& listeners = eventListeners[VSE_ControllerState];
    for (std::function<void(void*)>* listener : listeners)
        (*listener)(evt);
}

void VirtuSphereDllHost::OnMotorStateCallback(MotorStateEventStruct* evt) {
    if (evt == nullptr)
        return;

    if (!eventListeners.contains(VSE_MotorState))
        return;

    std::vector<std::function<void(void*)>*>& listeners = eventListeners[VSE_MotorState];
    for (std::function<void(void*)>* listener : listeners)
        (*listener)(evt);
}

void VirtuSphereDllHost::RegisterConnectionStateChangeListener(std::function<void(int)>* listener)
{
    if (listener == nullptr)
        return;

    connectionStateChangeListeners.push_back(listener);
}

void VirtuSphereDllHost::UnregisterConnectionStateChangeListener(std::function<void(int)>* listener)
{
    if (listener == nullptr)
        return;

    std::vector<std::function<void(int)>*>::iterator it;
    for (it = connectionStateChangeListeners.begin(); it != connectionStateChangeListeners.end(); ) {
        if (*it == listener)
            it = connectionStateChangeListeners.erase(it);
        else
            ++it;
    }
}

void VirtuSphereDllHost::RegisterEventListener(VirtuSphereEventType eventType, std::function<void(void*)>* listener)
{
    if (listener == nullptr)
        return;

    std::vector<std::function<void(void*)>*>* listeners = nullptr;
    if (!eventListeners.contains(eventType))
        eventListeners[eventType] = {};

    listeners = &eventListeners[eventType];
    listeners->push_back(listener);
}

void VirtuSphereDllHost::UnregisterEventListener(std::function<void(void*)>* listener)
{
    if (listener == nullptr)
        return;

    for (auto & kvpair : eventListeners)
    {
        std::vector<std::function<void(void*)>*>& listeners = kvpair.second;
        std::vector<std::function<void(void*)>*>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ) {
            if (*it == listener)
                it = listeners.erase(it);
            else
                ++it;
        }
    }
}