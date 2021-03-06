// Copyright Dr. Matthias Hölzl. All Rights Reserved.


#include "Pawns/CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


ACharacterBase::ACharacterBase()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterBase::MoveForward(float Value)
{
	if ((Value != 0.f) && (Controller != nullptr) && Controller->IsLocalPlayerController())
	{
		// Character models have to be oriented with x-axis facing forward.
		const FVector Direction{GetUnitVectorForAxis(EAxis::X)};
		AddMovementInput(Direction, Value);
	}
}

void ACharacterBase::MoveRight(float Value)
{
	if ((Value != 0.f) && (Controller != nullptr) && (Controller->IsLocalPlayerController()))
	{
		// UE4 uses a left-handed coordinate system and the x-axis points forward, so the y-axis points to the right.
		const FVector Direction{GetUnitVectorForAxis(EAxis::Y)};
		AddMovementInput(Direction, Value);
	}
}

void ACharacterBase::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * GetTurnRate() * GetWorld()->GetDeltaSeconds());
}

void ACharacterBase::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * GetLookUpRate() * GetWorld()->GetDeltaSeconds());
}

FVector ACharacterBase::GetUnitVectorForAxis(EAxis::Type Axis) const
{
	if (ensure(Controller != nullptr) && ensure((Axis == EAxis::X) || (Axis == EAxis::Y)))
	{
		// Compute a rotator that only takes into account our rotation around the up axis (i.e., yaw).
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation{0, Rotation.Yaw, 0};
		return FRotationMatrix(YawRotation).GetUnitAxis(Axis);
	}
	else
	{
		return FVector::ForwardVector;
	}
}

float ACharacterBase::GetTurnRate() const
{
	return 45.f;
}

float ACharacterBase::GetLookUpRate() const
{
	return 45.f;
}
