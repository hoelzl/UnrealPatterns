// Copyright Dr. Matthias Hölzl. All Rights Reserved.


#include "CoreGameplay/UnrealPatternsPlayerController.h"

#include "GameFramework/Character.h"
#include "Pawns/CharacterBase.h"


void AUnrealPatternsPlayerController::OnPossess(APawn* PossessedPawn)
{
	Super::OnPossess(PossessedPawn);

	ACharacterBase* ControlledCharacter{Cast<ACharacterBase>(PossessedPawn)};
	if (ensure(ControlledCharacter))
	{
		BindMovementEvents(ControlledCharacter);
		BindRotationEvents(ControlledCharacter);		
	}
}

void AUnrealPatternsPlayerController::OnUnPossess()
{
	Super::OnUnPossess();

	RemoveActionBindings();
	RemoveAxisBindings();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AUnrealPatternsPlayerController::BindMovementEvents(ACharacterBase* ControlledCharacter)
{
	check(InputComponent && InputComponent->IsRegistered());

	InputComponent->BindAction("Jump", IE_Pressed, ControlledCharacter, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, ControlledCharacter, &ACharacter::StopJumping);
	InputComponent->BindAxis("MoveForward", ControlledCharacter, &ACharacterBase::MoveForward);
	InputComponent->BindAxis("MoveRight", ControlledCharacter, &ACharacterBase::MoveRight);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AUnrealPatternsPlayerController::BindRotationEvents(ACharacterBase* ControlledCharacter)
{
	// We have 2 versions of the rotation bindings to handle different kinds of devices:
	// - "Turn" handles devices that provide an absolute delta, such as a mouse.
	// - "TurnRate" is for devices that provide a rate of change, such as an analog joystick.
	// Similarly for "LookUp".
	InputComponent->BindAxis("Turn", ControlledCharacter, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", ControlledCharacter, &ACharacterBase::TurnAtRate);
	InputComponent->BindAxis("LookUp", ControlledCharacter, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", ControlledCharacter, &ACharacterBase::LookUpAtRate);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AUnrealPatternsPlayerController::RemoveActionBindings()
{
	InputComponent->RemoveActionBinding("Jump", IE_Pressed);
	InputComponent->RemoveActionBinding("Jump", IE_Released);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AUnrealPatternsPlayerController::RemoveAxisBindings()
{
	InputComponent->AxisBindings.Empty();
}
