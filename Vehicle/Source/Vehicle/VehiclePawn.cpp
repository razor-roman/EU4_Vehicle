// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiclePawn.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

static const FName NAME_SteeringInput("Steer");
static const FName NAME_ThrottleInput("Throttle");

AVehiclePawn::AVehiclePawn()
{
	UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement());
	Vehicle4W->MinNormalizedTireLoad = 0.0f;
	Vehicle4W->MinNormalizedTireLoadFiltered = 0.2f;
	Vehicle4W->MaxNormalizedTireLoad = 2.0f;
	Vehicle4W->MaxNormalizedTireLoadFiltered = 2.0f;

	Vehicle4W->MaxEngineRPM = 5700.0f;
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->Reset();
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f,400.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(1890.0f,500.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(5730.0f,400.0f);

	Vehicle4W->SteeringCurve.GetRichCurve()->Reset();
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(0.0f,1.0f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(40.0f,0.7f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(120.0f,0.6f);

	Vehicle4W->DifferentialSetup.DifferentialType = EVehicleDifferential4W::LimitedSlip_4W;
	Vehicle4W->DifferentialSetup.FrontRearSplit = 0.65f;

	Vehicle4W->TransmissionSetup.bUseGearAutoBox = true;
	Vehicle4W->TransmissionSetup.GearSwitchTime = 0.15f;
	Vehicle4W->TransmissionSetup.GearAutoBoxLatency = 1.0f;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength=250.0f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	Camera->FieldOfView = 90.0f;
}

void AVehiclePawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	UpdateInAirControl(DeltaSeconds);
}

void AVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(NAME_ThrottleInput,this,&AVehiclePawn::ApplyThrottle);
	PlayerInputComponent->BindAxis(NAME_SteeringInput,this,&AVehiclePawn::ApplySteering);
	PlayerInputComponent->BindAxis("LookUp",this,&AVehiclePawn::LookUp);
	PlayerInputComponent->BindAxis("Turn",this,&AVehiclePawn::Turn);
	PlayerInputComponent->BindAction("HandBrake",IE_Pressed,this,&AVehiclePawn::OnHandBreakPressed);
	PlayerInputComponent->BindAction("HandBrake",IE_Released,this,&AVehiclePawn::OnHandBreakReleaed);
}

void AVehiclePawn::ApplyThrottle(float Val)
{
	GetVehicleMovementComponent()->SetThrottleInput(Val);
}

void AVehiclePawn::ApplySteering(float Val)
{
	GetVehicleMovementComponent()->SetSteeringInput(Val);
}

void AVehiclePawn::LookUp(float Val)
{
	if (Val!=0.0f)
	{
		AddControllerPitchInput(Val);
	}
}

void AVehiclePawn::Turn(float Val)
{
	if (Val!=0.0f)
	{
		AddControllerYawInput(Val);
	}
}

void AVehiclePawn::OnHandBreakPressed()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AVehiclePawn::OnHandBreakReleaed()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

void AVehiclePawn::UpdateInAirControl(float DeltaTime)
{
	if(UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement()))
	{
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);

		const FVector TraceStart = GetActorLocation() + FVector(0.0f,0.0f,50.0f);
		const FVector TraceEnd = GetActorLocation() + FVector(0.0f,0.0f,200.0f);

		FHitResult Hit;
		const bool bInAir = GetWorld()->LineTraceSingleByChannel(Hit,TraceStart,TraceEnd,ECC_Visibility,QueryParams);
		const bool bNotGrounded = FVector::DotProduct(GetActorUpVector(),FVector::UpVector) < 0.1f;

		if(bInAir || bNotGrounded)
		{
			const float ForwardInput = InputComponent->GetAxisValue(NAME_ThrottleInput);
			const float RightInput = InputComponent->GetAxisValue(NAME_SteeringInput);

			const float AirMovementForcePitch = 3.f;
			const float AirMovementForceRoll = !bInAir && bNotGrounded ? 20.f : 3.f;
			if(UPrimitiveComponent* VehicleMesh = Vehicle4W->UpdatedPrimitive)
			{
				const FVector MovementVector = FVector(RightInput* -AirMovementForceRoll,ForwardInput*AirMovementForcePitch,0.f) * DeltaTime*200.f;
				const FVector NewAngularMovement = GetActorRotation().RotateVector(MovementVector);
				VehicleMesh->SetPhysicsAngularVelocity(NewAngularMovement,true);
				
			}
		}
	}
}
