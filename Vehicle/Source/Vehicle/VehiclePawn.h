// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "VehiclePawn.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLE_API AVehiclePawn : public AWheeledVehicle
{
	
	GENERATED_BODY()
	AVehiclePawn();
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void ApplyThrottle(float Val);
	void ApplySteering(float Val);
	void LookUp(float Val);
	void Turn(float Val);

	void OnHandBreakPressed();
	void OnHandBreakReleaed();

	void UpdateInAirControl(float DeltaTime);
protected:
	UPROPERTY(Category=Camera,EditDefaultsOnly,BlueprintReadOnly,meta=(AllowPrivateAccess="true"))
	class UCameraComponent* Camera;

	UPROPERTY(Category=Camera,EditDefaultsOnly,BlueprintReadOnly,meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* SpringArm;
};
