// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VEHICLE_VehiclePawn_generated_h
#error "VehiclePawn.generated.h already included, missing '#pragma once' in VehiclePawn.h"
#endif
#define VEHICLE_VehiclePawn_generated_h

#define Vehicle_Source_Vehicle_VehiclePawn_h_16_SPARSE_DATA
#define Vehicle_Source_Vehicle_VehiclePawn_h_16_RPC_WRAPPERS
#define Vehicle_Source_Vehicle_VehiclePawn_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define Vehicle_Source_Vehicle_VehiclePawn_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVehiclePawn(); \
	friend struct Z_Construct_UClass_AVehiclePawn_Statics; \
public: \
	DECLARE_CLASS(AVehiclePawn, AWheeledVehicle, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Vehicle"), NO_API) \
	DECLARE_SERIALIZER(AVehiclePawn)


#define Vehicle_Source_Vehicle_VehiclePawn_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAVehiclePawn(); \
	friend struct Z_Construct_UClass_AVehiclePawn_Statics; \
public: \
	DECLARE_CLASS(AVehiclePawn, AWheeledVehicle, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Vehicle"), NO_API) \
	DECLARE_SERIALIZER(AVehiclePawn)


#define Vehicle_Source_Vehicle_VehiclePawn_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVehiclePawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVehiclePawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVehiclePawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVehiclePawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVehiclePawn(AVehiclePawn&&); \
	NO_API AVehiclePawn(const AVehiclePawn&); \
public:


#define Vehicle_Source_Vehicle_VehiclePawn_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVehiclePawn(AVehiclePawn&&); \
	NO_API AVehiclePawn(const AVehiclePawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVehiclePawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVehiclePawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVehiclePawn)


#define Vehicle_Source_Vehicle_VehiclePawn_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AVehiclePawn, Camera); } \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(AVehiclePawn, SpringArm); }


#define Vehicle_Source_Vehicle_VehiclePawn_h_12_PROLOG
#define Vehicle_Source_Vehicle_VehiclePawn_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_PRIVATE_PROPERTY_OFFSET \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_SPARSE_DATA \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_RPC_WRAPPERS \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_INCLASS \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Vehicle_Source_Vehicle_VehiclePawn_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_PRIVATE_PROPERTY_OFFSET \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_SPARSE_DATA \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_INCLASS_NO_PURE_DECLS \
	Vehicle_Source_Vehicle_VehiclePawn_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VEHICLE_API UClass* StaticClass<class AVehiclePawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Vehicle_Source_Vehicle_VehiclePawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
