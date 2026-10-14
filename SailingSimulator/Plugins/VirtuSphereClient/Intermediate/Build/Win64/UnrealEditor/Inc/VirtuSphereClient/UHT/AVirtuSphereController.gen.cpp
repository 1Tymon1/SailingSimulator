// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AVirtuSphereController.h"
#include "VirtuSphereClientStructs.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAVirtuSphereController() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_VirtuSphereClient();
VIRTUSPHERECLIENT_API UClass* Z_Construct_UClass_AVirtuSphereController();
VIRTUSPHERECLIENT_API UClass* Z_Construct_UClass_AVirtuSphereController_NoRegister();
VIRTUSPHERECLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FControllerStateEvent();
VIRTUSPHERECLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FMotorStateEvent();
VIRTUSPHERECLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FSpherePoseEvent();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AVirtuSphereController Function Connect **********************************
struct Z_Construct_UFunction_AVirtuSphereController_Connect_Statics
{
	struct VirtuSphereController_eventConnect_Parms
	{
		FString host;
		int32 port;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "CPP_Default_host", "127.0.0.1" },
		{ "CPP_Default_port", "4445" },
		{ "DisplayName", "Connect to VirtuSphere" },
		{ "Keywords", "VirtuSphereClient connect" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Connect constinit property declarations *******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_host;
	static const UECodeGen_Private::FIntPropertyParams NewProp_port;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Connect constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Connect Property Definitions ******************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::NewProp_host = { "host", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventConnect_Parms, host), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::NewProp_port = { "port", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventConnect_Parms, port), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::NewProp_host,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::NewProp_port,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::PropPointers) < 2048);
// ********** End Function Connect Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "Connect", 	Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::VirtuSphereController_eventConnect_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::VirtuSphereController_eventConnect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_Connect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_Connect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execConnect)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_host);
	P_GET_PROPERTY(FIntProperty,Z_Param_port);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Connect(Z_Param_host,Z_Param_port);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function Connect ************************************

// ********** Begin Class AVirtuSphereController Function Disconnect *******************************
struct Z_Construct_UFunction_AVirtuSphereController_Disconnect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "DisplayName", "Disconnect from VirtuSphere" },
		{ "Keywords", "VirtuSphereClient disconnect" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Disconnect constinit property declarations ****************************
// ********** End Function Disconnect constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_Disconnect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "Disconnect", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_Disconnect_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_Disconnect_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AVirtuSphereController_Disconnect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_Disconnect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execDisconnect)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Disconnect();
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function Disconnect *********************************

// ********** Begin Class AVirtuSphereController Function GetCurrentPing ***************************
struct Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics
{
	struct VirtuSphereController_eventGetCurrentPing_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "DisplayName", "Get current ping" },
		{ "Keywords", "VirtuSphereClient ping" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentPing constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentPing constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentPing Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventGetCurrentPing_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentPing Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "GetCurrentPing", 	Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::VirtuSphereController_eventGetCurrentPing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::VirtuSphereController_eventGetCurrentPing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execGetCurrentPing)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCurrentPing();
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function GetCurrentPing *****************************

// ********** Begin Class AVirtuSphereController Function IsConnected ******************************
struct Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics
{
	struct VirtuSphereController_eventIsConnected_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "DisplayName", "Is connected" },
		{ "Keywords", "VirtuSphereClient isconnected" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsConnected constinit property declarations ***************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsConnected constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsConnected Property Definitions **************************************
void Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((VirtuSphereController_eventIsConnected_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VirtuSphereController_eventIsConnected_Parms), &Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::PropPointers) < 2048);
// ********** End Function IsConnected Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "IsConnected", 	Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::VirtuSphereController_eventIsConnected_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::VirtuSphereController_eventIsConnected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_IsConnected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_IsConnected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execIsConnected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsConnected();
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function IsConnected ********************************

// ********** Begin Class AVirtuSphereController Function OnConnected ******************************
static FName NAME_AVirtuSphereController_OnConnected = FName(TEXT("OnConnected"));
void AVirtuSphereController::OnConnected()
{
	UFunction* Func = FindFunctionChecked(NAME_AVirtuSphereController_OnConnected);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnConnected_Implementation();
	}
}
struct Z_Construct_UFunction_AVirtuSphereController_OnConnected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnConnected constinit property declarations ***************************
// ********** End Function OnConnected constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_OnConnected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "OnConnected", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnConnected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_OnConnected_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AVirtuSphereController_OnConnected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_OnConnected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execOnConnected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnConnected_Implementation();
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function OnConnected ********************************

// ********** Begin Class AVirtuSphereController Function OnControllerState ************************
struct VirtuSphereController_eventOnControllerState_Parms
{
	FControllerStateEvent event;
};
static FName NAME_AVirtuSphereController_OnControllerState = FName(TEXT("OnControllerState"));
void AVirtuSphereController::OnControllerState(FControllerStateEvent event)
{
	UFunction* Func = FindFunctionChecked(NAME_AVirtuSphereController_OnControllerState);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		VirtuSphereController_eventOnControllerState_Parms Parms;
		Parms.event=event;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnControllerState_Implementation(event);
	}
}
struct Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnControllerState constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_event;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnControllerState constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnControllerState Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::NewProp_event = { "event", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventOnControllerState_Parms, event), Z_Construct_UScriptStruct_FControllerStateEvent, METADATA_PARAMS(0, nullptr) }; // 2922718470
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::NewProp_event,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::PropPointers) < 2048);
// ********** End Function OnControllerState Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "OnControllerState", 	Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::PropPointers), 
sizeof(VirtuSphereController_eventOnControllerState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(VirtuSphereController_eventOnControllerState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_OnControllerState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_OnControllerState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execOnControllerState)
{
	P_GET_STRUCT(FControllerStateEvent,Z_Param_event);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnControllerState_Implementation(Z_Param_event);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function OnControllerState **************************

// ********** Begin Class AVirtuSphereController Function OnDisconnected ***************************
static FName NAME_AVirtuSphereController_OnDisconnected = FName(TEXT("OnDisconnected"));
void AVirtuSphereController::OnDisconnected()
{
	UFunction* Func = FindFunctionChecked(NAME_AVirtuSphereController_OnDisconnected);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnDisconnected_Implementation();
	}
}
struct Z_Construct_UFunction_AVirtuSphereController_OnDisconnected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnDisconnected constinit property declarations ************************
// ********** End Function OnDisconnected constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_OnDisconnected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "OnDisconnected", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnDisconnected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_OnDisconnected_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AVirtuSphereController_OnDisconnected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_OnDisconnected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execOnDisconnected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDisconnected_Implementation();
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function OnDisconnected *****************************

// ********** Begin Class AVirtuSphereController Function OnMotorState *****************************
struct VirtuSphereController_eventOnMotorState_Parms
{
	FMotorStateEvent event;
};
static FName NAME_AVirtuSphereController_OnMotorState = FName(TEXT("OnMotorState"));
void AVirtuSphereController::OnMotorState(FMotorStateEvent event)
{
	UFunction* Func = FindFunctionChecked(NAME_AVirtuSphereController_OnMotorState);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		VirtuSphereController_eventOnMotorState_Parms Parms;
		Parms.event=event;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnMotorState_Implementation(event);
	}
}
struct Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnMotorState constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_event;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnMotorState constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnMotorState Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::NewProp_event = { "event", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventOnMotorState_Parms, event), Z_Construct_UScriptStruct_FMotorStateEvent, METADATA_PARAMS(0, nullptr) }; // 2569533948
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::NewProp_event,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::PropPointers) < 2048);
// ********** End Function OnMotorState Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "OnMotorState", 	Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::PropPointers), 
sizeof(VirtuSphereController_eventOnMotorState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(VirtuSphereController_eventOnMotorState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_OnMotorState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_OnMotorState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execOnMotorState)
{
	P_GET_STRUCT(FMotorStateEvent,Z_Param_event);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMotorState_Implementation(Z_Param_event);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function OnMotorState *******************************

// ********** Begin Class AVirtuSphereController Function OnSpherePose *****************************
struct VirtuSphereController_eventOnSpherePose_Parms
{
	FSpherePoseEvent event;
};
static FName NAME_AVirtuSphereController_OnSpherePose = FName(TEXT("OnSpherePose"));
void AVirtuSphereController::OnSpherePose(FSpherePoseEvent event)
{
	UFunction* Func = FindFunctionChecked(NAME_AVirtuSphereController_OnSpherePose);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		VirtuSphereController_eventOnSpherePose_Parms Parms;
		Parms.event=event;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnSpherePose_Implementation(event);
	}
}
struct Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnSpherePose constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_event;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnSpherePose constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnSpherePose Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::NewProp_event = { "event", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventOnSpherePose_Parms, event), Z_Construct_UScriptStruct_FSpherePoseEvent, METADATA_PARAMS(0, nullptr) }; // 3886788541
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::NewProp_event,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::PropPointers) < 2048);
// ********** End Function OnSpherePose Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "OnSpherePose", 	Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::PropPointers), 
sizeof(VirtuSphereController_eventOnSpherePose_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(VirtuSphereController_eventOnSpherePose_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_OnSpherePose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_OnSpherePose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execOnSpherePose)
{
	P_GET_STRUCT(FSpherePoseEvent,Z_Param_event);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSpherePose_Implementation(Z_Param_event);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function OnSpherePose *******************************

// ********** Begin Class AVirtuSphereController Function RequestControllerStateUpdates ************
struct Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics
{
	struct VirtuSphereController_eventRequestControllerStateUpdates_Parms
	{
		int32 sendRate;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "CPP_Default_sendRate", "10" },
		{ "DisplayName", "Request ControllerState events" },
		{ "Keywords", "VirtuSphereClient controller state" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestControllerStateUpdates constinit property declarations *********
	static const UECodeGen_Private::FIntPropertyParams NewProp_sendRate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestControllerStateUpdates constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestControllerStateUpdates Property Definitions ********************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::NewProp_sendRate = { "sendRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventRequestControllerStateUpdates_Parms, sendRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::NewProp_sendRate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::PropPointers) < 2048);
// ********** End Function RequestControllerStateUpdates Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "RequestControllerStateUpdates", 	Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::VirtuSphereController_eventRequestControllerStateUpdates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::VirtuSphereController_eventRequestControllerStateUpdates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execRequestControllerStateUpdates)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_sendRate);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestControllerStateUpdates(Z_Param_sendRate);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function RequestControllerStateUpdates **************

// ********** Begin Class AVirtuSphereController Function RequestMotorStateUpdates *****************
struct Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics
{
	struct VirtuSphereController_eventRequestMotorStateUpdates_Parms
	{
		int32 sendRate;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "CPP_Default_sendRate", "10" },
		{ "DisplayName", "Request MotorState events" },
		{ "Keywords", "VirtuSphereClient motor state" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestMotorStateUpdates constinit property declarations **************
	static const UECodeGen_Private::FIntPropertyParams NewProp_sendRate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestMotorStateUpdates constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestMotorStateUpdates Property Definitions *************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::NewProp_sendRate = { "sendRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventRequestMotorStateUpdates_Parms, sendRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::NewProp_sendRate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::PropPointers) < 2048);
// ********** End Function RequestMotorStateUpdates Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "RequestMotorStateUpdates", 	Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::VirtuSphereController_eventRequestMotorStateUpdates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::VirtuSphereController_eventRequestMotorStateUpdates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execRequestMotorStateUpdates)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_sendRate);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestMotorStateUpdates(Z_Param_sendRate);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function RequestMotorStateUpdates *******************

// ********** Begin Class AVirtuSphereController Function RequestSpherePoseUpdates *****************
struct Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics
{
	struct VirtuSphereController_eventRequestSpherePoseUpdates_Parms
	{
		int32 sendRate;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "CPP_Default_sendRate", "10" },
		{ "DisplayName", "Request SpherePose events" },
		{ "Keywords", "VirtuSphereClient pose" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestSpherePoseUpdates constinit property declarations **************
	static const UECodeGen_Private::FIntPropertyParams NewProp_sendRate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestSpherePoseUpdates constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestSpherePoseUpdates Property Definitions *************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::NewProp_sendRate = { "sendRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventRequestSpherePoseUpdates_Parms, sendRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::NewProp_sendRate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::PropPointers) < 2048);
// ********** End Function RequestSpherePoseUpdates Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "RequestSpherePoseUpdates", 	Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::VirtuSphereController_eventRequestSpherePoseUpdates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::VirtuSphereController_eventRequestSpherePoseUpdates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execRequestSpherePoseUpdates)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_sendRate);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestSpherePoseUpdates(Z_Param_sendRate);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function RequestSpherePoseUpdates *******************

// ********** Begin Class AVirtuSphereController Function SetMotorPower ****************************
struct Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics
{
	struct VirtuSphereController_eventSetMotorPower_Parms
	{
		bool enabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "DisplayName", "Set motor power" },
		{ "Keywords", "VirtuSphereClient set power" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetMotorPower constinit property declarations *************************
	static void NewProp_enabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_enabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMotorPower constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMotorPower Property Definitions ************************************
void Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::NewProp_enabled_SetBit(void* Obj)
{
	((VirtuSphereController_eventSetMotorPower_Parms*)Obj)->enabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::NewProp_enabled = { "enabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VirtuSphereController_eventSetMotorPower_Parms), &Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::NewProp_enabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::NewProp_enabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::PropPointers) < 2048);
// ********** End Function SetMotorPower Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "SetMotorPower", 	Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::VirtuSphereController_eventSetMotorPower_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::VirtuSphereController_eventSetMotorPower_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_SetMotorPower()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_SetMotorPower_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execSetMotorPower)
{
	P_GET_UBOOL(Z_Param_enabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMotorPower(Z_Param_enabled);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function SetMotorPower ******************************

// ********** Begin Class AVirtuSphereController Function SetSpherePose ****************************
struct Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics
{
	struct VirtuSphereController_eventSetSpherePose_Parms
	{
		float velocity;
		float direction;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "DisplayName", "Set sphere pose" },
		{ "Keywords", "VirtuSphereClient set pose" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSpherePose constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_velocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_direction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSpherePose constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSpherePose Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::NewProp_velocity = { "velocity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventSetSpherePose_Parms, velocity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::NewProp_direction = { "direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventSetSpherePose_Parms, direction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::NewProp_velocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::NewProp_direction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::PropPointers) < 2048);
// ********** End Function SetSpherePose Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "SetSpherePose", 	Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::VirtuSphereController_eventSetSpherePose_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::VirtuSphereController_eventSetSpherePose_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_SetSpherePose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_SetSpherePose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execSetSpherePose)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_velocity);
	P_GET_PROPERTY(FFloatProperty,Z_Param_direction);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSpherePose(Z_Param_velocity,Z_Param_direction);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function SetSpherePose ******************************

// ********** Begin Class AVirtuSphereController Function SetSphereVector **************************
struct Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics
{
	struct VirtuSphereController_eventSetSphereVector_Parms
	{
		float vx;
		float vy;
		float wz;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VirtuSphereClient" },
		{ "DisplayName", "Set sphere vector" },
		{ "Keywords", "VirtuSphereClient set vector" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSphereVector constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_vx;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_vy;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_wz;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSphereVector constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSphereVector Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::NewProp_vx = { "vx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventSetSphereVector_Parms, vx), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::NewProp_vy = { "vy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventSetSphereVector_Parms, vy), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::NewProp_wz = { "wz", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VirtuSphereController_eventSetSphereVector_Parms, wz), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::NewProp_vx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::NewProp_vy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::NewProp_wz,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::PropPointers) < 2048);
// ********** End Function SetSphereVector Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVirtuSphereController, nullptr, "SetSphereVector", 	Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::VirtuSphereController_eventSetSphereVector_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::VirtuSphereController_eventSetSphereVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVirtuSphereController_SetSphereVector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVirtuSphereController_SetSphereVector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVirtuSphereController::execSetSphereVector)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_vx);
	P_GET_PROPERTY(FFloatProperty,Z_Param_vy);
	P_GET_PROPERTY(FFloatProperty,Z_Param_wz);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSphereVector(Z_Param_vx,Z_Param_vy,Z_Param_wz);
	P_NATIVE_END;
}
// ********** End Class AVirtuSphereController Function SetSphereVector ****************************

// ********** Begin Class AVirtuSphereController ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AVirtuSphereController;
UClass* AVirtuSphereController::GetPrivateStaticClass()
{
	using TClass = AVirtuSphereController;
	if (!Z_Registration_Info_UClass_AVirtuSphereController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("VirtuSphereController"),
			Z_Registration_Info_UClass_AVirtuSphereController.InnerSingleton,
			StaticRegisterNativesAVirtuSphereController,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AVirtuSphereController.InnerSingleton;
}
UClass* Z_Construct_UClass_AVirtuSphereController_NoRegister()
{
	return AVirtuSphereController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AVirtuSphereController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AVirtuSphereController.h" },
		{ "ModuleRelativePath", "Public/AVirtuSphereController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AVirtuSphereController constinit property declarations *******************
// ********** End Class AVirtuSphereController constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Connect"), .Pointer = &AVirtuSphereController::execConnect },
		{ .NameUTF8 = UTF8TEXT("Disconnect"), .Pointer = &AVirtuSphereController::execDisconnect },
		{ .NameUTF8 = UTF8TEXT("GetCurrentPing"), .Pointer = &AVirtuSphereController::execGetCurrentPing },
		{ .NameUTF8 = UTF8TEXT("IsConnected"), .Pointer = &AVirtuSphereController::execIsConnected },
		{ .NameUTF8 = UTF8TEXT("OnConnected"), .Pointer = &AVirtuSphereController::execOnConnected },
		{ .NameUTF8 = UTF8TEXT("OnControllerState"), .Pointer = &AVirtuSphereController::execOnControllerState },
		{ .NameUTF8 = UTF8TEXT("OnDisconnected"), .Pointer = &AVirtuSphereController::execOnDisconnected },
		{ .NameUTF8 = UTF8TEXT("OnMotorState"), .Pointer = &AVirtuSphereController::execOnMotorState },
		{ .NameUTF8 = UTF8TEXT("OnSpherePose"), .Pointer = &AVirtuSphereController::execOnSpherePose },
		{ .NameUTF8 = UTF8TEXT("RequestControllerStateUpdates"), .Pointer = &AVirtuSphereController::execRequestControllerStateUpdates },
		{ .NameUTF8 = UTF8TEXT("RequestMotorStateUpdates"), .Pointer = &AVirtuSphereController::execRequestMotorStateUpdates },
		{ .NameUTF8 = UTF8TEXT("RequestSpherePoseUpdates"), .Pointer = &AVirtuSphereController::execRequestSpherePoseUpdates },
		{ .NameUTF8 = UTF8TEXT("SetMotorPower"), .Pointer = &AVirtuSphereController::execSetMotorPower },
		{ .NameUTF8 = UTF8TEXT("SetSpherePose"), .Pointer = &AVirtuSphereController::execSetSpherePose },
		{ .NameUTF8 = UTF8TEXT("SetSphereVector"), .Pointer = &AVirtuSphereController::execSetSphereVector },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AVirtuSphereController_Connect, "Connect" }, // 200296642
		{ &Z_Construct_UFunction_AVirtuSphereController_Disconnect, "Disconnect" }, // 941004852
		{ &Z_Construct_UFunction_AVirtuSphereController_GetCurrentPing, "GetCurrentPing" }, // 1929967814
		{ &Z_Construct_UFunction_AVirtuSphereController_IsConnected, "IsConnected" }, // 4040705706
		{ &Z_Construct_UFunction_AVirtuSphereController_OnConnected, "OnConnected" }, // 3827545950
		{ &Z_Construct_UFunction_AVirtuSphereController_OnControllerState, "OnControllerState" }, // 4220050971
		{ &Z_Construct_UFunction_AVirtuSphereController_OnDisconnected, "OnDisconnected" }, // 2821825593
		{ &Z_Construct_UFunction_AVirtuSphereController_OnMotorState, "OnMotorState" }, // 2390321969
		{ &Z_Construct_UFunction_AVirtuSphereController_OnSpherePose, "OnSpherePose" }, // 2376430003
		{ &Z_Construct_UFunction_AVirtuSphereController_RequestControllerStateUpdates, "RequestControllerStateUpdates" }, // 3523767326
		{ &Z_Construct_UFunction_AVirtuSphereController_RequestMotorStateUpdates, "RequestMotorStateUpdates" }, // 2354081165
		{ &Z_Construct_UFunction_AVirtuSphereController_RequestSpherePoseUpdates, "RequestSpherePoseUpdates" }, // 3998051988
		{ &Z_Construct_UFunction_AVirtuSphereController_SetMotorPower, "SetMotorPower" }, // 3894581728
		{ &Z_Construct_UFunction_AVirtuSphereController_SetSpherePose, "SetSpherePose" }, // 1416986432
		{ &Z_Construct_UFunction_AVirtuSphereController_SetSphereVector, "SetSphereVector" }, // 1918216569
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVirtuSphereController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AVirtuSphereController_Statics
UObject* (*const Z_Construct_UClass_AVirtuSphereController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_VirtuSphereClient,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVirtuSphereController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVirtuSphereController_Statics::ClassParams = {
	&AVirtuSphereController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVirtuSphereController_Statics::Class_MetaDataParams), Z_Construct_UClass_AVirtuSphereController_Statics::Class_MetaDataParams)
};
void AVirtuSphereController::StaticRegisterNativesAVirtuSphereController()
{
	UClass* Class = AVirtuSphereController::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AVirtuSphereController_Statics::Funcs));
}
UClass* Z_Construct_UClass_AVirtuSphereController()
{
	if (!Z_Registration_Info_UClass_AVirtuSphereController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVirtuSphereController.OuterSingleton, Z_Construct_UClass_AVirtuSphereController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVirtuSphereController.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AVirtuSphereController);
AVirtuSphereController::~AVirtuSphereController() {}
// ********** End Class AVirtuSphereController *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h__Script_VirtuSphereClient_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVirtuSphereController, AVirtuSphereController::StaticClass, TEXT("AVirtuSphereController"), &Z_Registration_Info_UClass_AVirtuSphereController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVirtuSphereController), 17432018U) },
	};
}; // Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h__Script_VirtuSphereClient_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h__Script_VirtuSphereClient_1394923682{
	TEXT("/Script/VirtuSphereClient"),
	Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h__Script_VirtuSphereClient_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_AVirtuSphereController_h__Script_VirtuSphereClient_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
