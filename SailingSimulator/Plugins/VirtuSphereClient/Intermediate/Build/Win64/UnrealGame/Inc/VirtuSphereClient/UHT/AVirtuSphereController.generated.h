// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AVirtuSphereController.h"

#ifdef VIRTUSPHERECLIENT_AVirtuSphereController_generated_h
#error "AVirtuSphereController.generated.h already included, missing '#pragma once' in AVirtuSphereController.h"
#endif
#define VIRTUSPHERECLIENT_AVirtuSphereController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FControllerStateEvent;
struct FMotorStateEvent;
struct FSpherePoseEvent;

// ********** Begin Class AVirtuSphereController ***************************************************
#define FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnMotorState); \
	DECLARE_FUNCTION(execOnControllerState); \
	DECLARE_FUNCTION(execOnSpherePose); \
	DECLARE_FUNCTION(execOnDisconnected); \
	DECLARE_FUNCTION(execOnConnected); \
	DECLARE_FUNCTION(execSetMotorPower); \
	DECLARE_FUNCTION(execSetSphereVector); \
	DECLARE_FUNCTION(execSetSpherePose); \
	DECLARE_FUNCTION(execRequestMotorStateUpdates); \
	DECLARE_FUNCTION(execRequestControllerStateUpdates); \
	DECLARE_FUNCTION(execRequestSpherePoseUpdates); \
	DECLARE_FUNCTION(execGetCurrentPing); \
	DECLARE_FUNCTION(execIsConnected); \
	DECLARE_FUNCTION(execDisconnect); \
	DECLARE_FUNCTION(execConnect);


#define FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_16_CALLBACK_WRAPPERS
struct Z_Construct_UClass_AVirtuSphereController_Statics;
VIRTUSPHERECLIENT_API UClass* Z_Construct_UClass_AVirtuSphereController_NoRegister();

#define FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVirtuSphereController(); \
	friend struct ::Z_Construct_UClass_AVirtuSphereController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend VIRTUSPHERECLIENT_API UClass* ::Z_Construct_UClass_AVirtuSphereController_NoRegister(); \
public: \
	DECLARE_CLASS2(AVirtuSphereController, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VirtuSphereClient"), Z_Construct_UClass_AVirtuSphereController_NoRegister) \
	DECLARE_SERIALIZER(AVirtuSphereController)


#define FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AVirtuSphereController(AVirtuSphereController&&) = delete; \
	AVirtuSphereController(const AVirtuSphereController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVirtuSphereController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVirtuSphereController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVirtuSphereController) \
	NO_API virtual ~AVirtuSphereController();


#define FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_13_PROLOG
#define FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_16_CALLBACK_WRAPPERS \
	FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_16_INCLASS_NO_PURE_DECLS \
	FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AVirtuSphereController;

// ********** End Class AVirtuSphereController *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
