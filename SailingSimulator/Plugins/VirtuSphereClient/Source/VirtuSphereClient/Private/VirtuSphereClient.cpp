// Copyright Epic Games, Inc. All Rights Reserved.

#include "VirtuSphereClient.h"
#include "VirtuSphereDllHost.h"
#include "Misc/App.h"

#define LOCTEXT_NAMESPACE "FVirtuSphereClientModule"

void FVirtuSphereClientModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	char appName[1024];
	size_t n;
	wcstombs_s(&n, appName, 1024, (const char_t*)(*FApp::GetName()), 1023);

	//TODO: https://stackoverflow.com/questions/60700302/win32-api-to-get-machine-uuid
	/*char deviceUUID[128];
	LPWSTR pHardwareId[128];
	DWORD cHardwareId = 128;
	LONG lResult = ERROR_SUCCESS;
	lResult = RegGetValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Cryptography", L"MachineGuid", RRF_RT_REG_SZ, NULL, pHardwareId, &cHardwareId);

	if (lResult == ERROR_SUCCESS) {
		n = 0;
		wcstombs_s(&n, deviceUUID, 128, (const wchar_t*)pHardwareId, 128);
	} else {
		strcpy_s(deviceUUID, 37, "AC4F1154-1953-4D14-B55C-4E0B38B01DF7");
	}*/
	const char* deviceUUID = "AC4F1154-1953-4D14-B55C-4E0B38B01DF7";

	dllHost = new VirtuSphereDllHost(appName, deviceUUID);
}

void FVirtuSphereClientModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	delete dllHost;
	dllHost = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVirtuSphereClientModule, VirtuSphereClient)