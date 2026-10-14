// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VirtuSphereClientStructs.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeVirtuSphereClientStructs() {}

// ********** Begin Cross Module References ********************************************************
UPackage* Z_Construct_UPackage__Script_VirtuSphereClient();
VIRTUSPHERECLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FControllerStateEvent();
VIRTUSPHERECLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FMotorStateEvent();
VIRTUSPHERECLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FSpherePoseEvent();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FSpherePoseEvent **************************************************
struct Z_Construct_UScriptStruct_FSpherePoseEvent_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSpherePoseEvent); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSpherePoseEvent); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_timestamp_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_velocity_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Unix timestamp in microseconds\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unix timestamp in microseconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_direction_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[m/s]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[m/s]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_targetVelocityVectorX_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[deg]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[deg]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_targetVelocityVectorY_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[m/s]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[m/s]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_targetVelocityVectorZ_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[m/s]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[m/s]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_actualVelocityVectorX_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[rad/s]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[rad/s]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_actualVelocityVectorY_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[m/s]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[m/s]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_actualVelocityVectorZ_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[m/s]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[m/s]" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSpherePoseEvent constinit property declarations ******************
	static const UECodeGen_Private::FInt64PropertyParams NewProp_timestamp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_velocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_direction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_targetVelocityVectorX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_targetVelocityVectorY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_targetVelocityVectorZ;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_actualVelocityVectorX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_actualVelocityVectorY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_actualVelocityVectorZ;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSpherePoseEvent constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSpherePoseEvent>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSpherePoseEvent_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSpherePoseEvent;
class UScriptStruct* FSpherePoseEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSpherePoseEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSpherePoseEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSpherePoseEvent, (UObject*)Z_Construct_UPackage__Script_VirtuSphereClient(), TEXT("SpherePoseEvent"));
	}
	return Z_Registration_Info_UScriptStruct_FSpherePoseEvent.OuterSingleton;
	}

// ********** Begin ScriptStruct FSpherePoseEvent Property Definitions *****************************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_timestamp = { "timestamp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpherePoseEvent, timestamp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_timestamp_MetaData), NewProp_timestamp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_velocity = { "velocity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpherePoseEvent, velocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_velocity_MetaData), NewProp_velocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_direction = { "direction", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpherePoseEvent, direction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_direction_MetaData), NewProp_direction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_targetVelocityVectorX = { "targetVelocityVectorX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpherePoseEvent, targetVelocityVectorX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_targetVelocityVectorX_MetaData), NewProp_targetVelocityVectorX_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_targetVelocityVectorY = { "targetVelocityVectorY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpherePoseEvent, targetVelocityVectorY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_targetVelocityVectorY_MetaData), NewProp_targetVelocityVectorY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_targetVelocityVectorZ = { "targetVelocityVectorZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpherePoseEvent, targetVelocityVectorZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_targetVelocityVectorZ_MetaData), NewProp_targetVelocityVectorZ_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_actualVelocityVectorX = { "actualVelocityVectorX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpherePoseEvent, actualVelocityVectorX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_actualVelocityVectorX_MetaData), NewProp_actualVelocityVectorX_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_actualVelocityVectorY = { "actualVelocityVectorY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpherePoseEvent, actualVelocityVectorY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_actualVelocityVectorY_MetaData), NewProp_actualVelocityVectorY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_actualVelocityVectorZ = { "actualVelocityVectorZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpherePoseEvent, actualVelocityVectorZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_actualVelocityVectorZ_MetaData), NewProp_actualVelocityVectorZ_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_timestamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_velocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_direction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_targetVelocityVectorX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_targetVelocityVectorY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_targetVelocityVectorZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_actualVelocityVectorX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_actualVelocityVectorY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewProp_actualVelocityVectorZ,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSpherePoseEvent Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_VirtuSphereClient,
	nullptr,
	&NewStructOps,
	"SpherePoseEvent",
	Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::PropPointers),
	sizeof(FSpherePoseEvent),
	alignof(FSpherePoseEvent),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSpherePoseEvent()
{
	if (!Z_Registration_Info_UScriptStruct_FSpherePoseEvent.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSpherePoseEvent.InnerSingleton, Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSpherePoseEvent.InnerSingleton);
}
// ********** End ScriptStruct FSpherePoseEvent ****************************************************

// ********** Begin ScriptStruct FControllerStateEvent *********************************************
struct Z_Construct_UScriptStruct_FControllerStateEvent_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FControllerStateEvent); }
	static inline consteval int16 GetStructAlignment() { return alignof(FControllerStateEvent); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_timestamp_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_controllerId_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Unix timestamp in microseconds\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unix timestamp in microseconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_statusRegister_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_errorRegister_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_electronicVoltage_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_powerVoltage_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[V]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[V]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_powerStageTemperature_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[V]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[V]" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FControllerStateEvent constinit property declarations *************
	static const UECodeGen_Private::FInt64PropertyParams NewProp_timestamp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_controllerId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_statusRegister;
	static const UECodeGen_Private::FIntPropertyParams NewProp_errorRegister;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_electronicVoltage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_powerVoltage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_powerStageTemperature;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FControllerStateEvent constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FControllerStateEvent>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FControllerStateEvent_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FControllerStateEvent;
class UScriptStruct* FControllerStateEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FControllerStateEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FControllerStateEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FControllerStateEvent, (UObject*)Z_Construct_UPackage__Script_VirtuSphereClient(), TEXT("ControllerStateEvent"));
	}
	return Z_Registration_Info_UScriptStruct_FControllerStateEvent.OuterSingleton;
	}

// ********** Begin ScriptStruct FControllerStateEvent Property Definitions ************************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_timestamp = { "timestamp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FControllerStateEvent, timestamp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_timestamp_MetaData), NewProp_timestamp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_controllerId = { "controllerId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FControllerStateEvent, controllerId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_controllerId_MetaData), NewProp_controllerId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_statusRegister = { "statusRegister", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FControllerStateEvent, statusRegister), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_statusRegister_MetaData), NewProp_statusRegister_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_errorRegister = { "errorRegister", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FControllerStateEvent, errorRegister), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_errorRegister_MetaData), NewProp_errorRegister_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_electronicVoltage = { "electronicVoltage", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FControllerStateEvent, electronicVoltage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_electronicVoltage_MetaData), NewProp_electronicVoltage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_powerVoltage = { "powerVoltage", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FControllerStateEvent, powerVoltage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_powerVoltage_MetaData), NewProp_powerVoltage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_powerStageTemperature = { "powerStageTemperature", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FControllerStateEvent, powerStageTemperature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_powerStageTemperature_MetaData), NewProp_powerStageTemperature_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FControllerStateEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_timestamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_controllerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_statusRegister,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_errorRegister,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_electronicVoltage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_powerVoltage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewProp_powerStageTemperature,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FControllerStateEvent_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FControllerStateEvent Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FControllerStateEvent_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_VirtuSphereClient,
	nullptr,
	&NewStructOps,
	"ControllerStateEvent",
	Z_Construct_UScriptStruct_FControllerStateEvent_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FControllerStateEvent_Statics::PropPointers),
	sizeof(FControllerStateEvent),
	alignof(FControllerStateEvent),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FControllerStateEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FControllerStateEvent_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FControllerStateEvent()
{
	if (!Z_Registration_Info_UScriptStruct_FControllerStateEvent.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FControllerStateEvent.InnerSingleton, Z_Construct_UScriptStruct_FControllerStateEvent_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FControllerStateEvent.InnerSingleton);
}
// ********** End ScriptStruct FControllerStateEvent ***********************************************

// ********** Begin ScriptStruct FMotorStateEvent **************************************************
struct Z_Construct_UScriptStruct_FMotorStateEvent_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FMotorStateEvent); }
	static inline consteval int16 GetStructAlignment() { return alignof(FMotorStateEvent); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_timestamp_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_controllerId_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Unix timestamp in microseconds\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unix timestamp in microseconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_motorFlags_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_hallPosition_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_encoderPosition_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[counts]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[counts]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_motorTargetVelocity_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[counts]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[counts]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_motorActualVelocity_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[RPM]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[RPM]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_motorVoltage_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[RPM]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[RPM]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_motorTargetCurrent_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[V]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[V]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_motorActualCurrent_MetaData[] = {
		{ "Category", "VirtuSphereClient | Struct Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//[A]\n" },
#endif
		{ "ModuleRelativePath", "Public/VirtuSphereClientStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "[A]" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FMotorStateEvent constinit property declarations ******************
	static const UECodeGen_Private::FInt64PropertyParams NewProp_timestamp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_controllerId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_motorFlags;
	static const UECodeGen_Private::FIntPropertyParams NewProp_hallPosition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_encoderPosition;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_motorTargetVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_motorActualVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_motorVoltage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_motorTargetCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_motorActualCurrent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FMotorStateEvent constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMotorStateEvent>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FMotorStateEvent_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMotorStateEvent;
class UScriptStruct* FMotorStateEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FMotorStateEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FMotorStateEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMotorStateEvent, (UObject*)Z_Construct_UPackage__Script_VirtuSphereClient(), TEXT("MotorStateEvent"));
	}
	return Z_Registration_Info_UScriptStruct_FMotorStateEvent.OuterSingleton;
	}

// ********** Begin ScriptStruct FMotorStateEvent Property Definitions *****************************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_timestamp = { "timestamp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, timestamp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_timestamp_MetaData), NewProp_timestamp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_controllerId = { "controllerId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, controllerId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_controllerId_MetaData), NewProp_controllerId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorFlags = { "motorFlags", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, motorFlags), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_motorFlags_MetaData), NewProp_motorFlags_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_hallPosition = { "hallPosition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, hallPosition), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_hallPosition_MetaData), NewProp_hallPosition_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_encoderPosition = { "encoderPosition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, encoderPosition), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_encoderPosition_MetaData), NewProp_encoderPosition_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorTargetVelocity = { "motorTargetVelocity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, motorTargetVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_motorTargetVelocity_MetaData), NewProp_motorTargetVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorActualVelocity = { "motorActualVelocity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, motorActualVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_motorActualVelocity_MetaData), NewProp_motorActualVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorVoltage = { "motorVoltage", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, motorVoltage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_motorVoltage_MetaData), NewProp_motorVoltage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorTargetCurrent = { "motorTargetCurrent", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, motorTargetCurrent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_motorTargetCurrent_MetaData), NewProp_motorTargetCurrent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorActualCurrent = { "motorActualCurrent", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotorStateEvent, motorActualCurrent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_motorActualCurrent_MetaData), NewProp_motorActualCurrent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMotorStateEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_timestamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_controllerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorFlags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_hallPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_encoderPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorTargetVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorActualVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorVoltage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorTargetCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewProp_motorActualCurrent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMotorStateEvent_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FMotorStateEvent Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMotorStateEvent_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_VirtuSphereClient,
	nullptr,
	&NewStructOps,
	"MotorStateEvent",
	Z_Construct_UScriptStruct_FMotorStateEvent_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMotorStateEvent_Statics::PropPointers),
	sizeof(FMotorStateEvent),
	alignof(FMotorStateEvent),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMotorStateEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMotorStateEvent_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMotorStateEvent()
{
	if (!Z_Registration_Info_UScriptStruct_FMotorStateEvent.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMotorStateEvent.InnerSingleton, Z_Construct_UScriptStruct_FMotorStateEvent_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FMotorStateEvent.InnerSingleton);
}
// ********** End ScriptStruct FMotorStateEvent ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_VirtuSphereClientStructs_h__Script_VirtuSphereClient_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSpherePoseEvent::StaticStruct, Z_Construct_UScriptStruct_FSpherePoseEvent_Statics::NewStructOps, TEXT("SpherePoseEvent"),&Z_Registration_Info_UScriptStruct_FSpherePoseEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSpherePoseEvent), 3886788541U) },
		{ FControllerStateEvent::StaticStruct, Z_Construct_UScriptStruct_FControllerStateEvent_Statics::NewStructOps, TEXT("ControllerStateEvent"),&Z_Registration_Info_UScriptStruct_FControllerStateEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FControllerStateEvent), 2922718470U) },
		{ FMotorStateEvent::StaticStruct, Z_Construct_UScriptStruct_FMotorStateEvent_Statics::NewStructOps, TEXT("MotorStateEvent"),&Z_Registration_Info_UScriptStruct_FMotorStateEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMotorStateEvent), 2569533948U) },
	};
}; // Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_VirtuSphereClientStructs_h__Script_VirtuSphereClient_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_VirtuSphereClientStructs_h__Script_VirtuSphereClient_3187797890{
	TEXT("/Script/VirtuSphereClient"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_VirtuSphereClientStructs_h__Script_VirtuSphereClient_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projekty_SailingSimulator_SailingSimulator_Plugins_VirtuSphereClient_Source_VirtuSphereClient_Public_VirtuSphereClientStructs_h__Script_VirtuSphereClient_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
