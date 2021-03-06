// Copyright Dr. Matthias Hölzl. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Pawns/CharacterBase.h"

#include "UnrealPatternsPlayerController.generated.h"

/**
 * Player controller for the Unreal Patterns example.
 */
UCLASS()
class UNREALPATTERNS_API AUnrealPatternsPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn* PossessedPawn) override;
	virtual void OnUnPossess() override;

private:
	void BindMovementEvents(ACharacterBase* ControlledCharacter);
	void BindRotationEvents(ACharacterBase* ControlledCharacter);
	void RemoveActionBindings();
	void RemoveAxisBindings();
};
