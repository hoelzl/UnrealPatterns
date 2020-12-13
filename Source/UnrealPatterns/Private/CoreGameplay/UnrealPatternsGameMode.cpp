// Copyright Dr. Matthias Hölzl. All Rights Reserved.

#include "CoreGameplay/UnrealPatternsGameMode.h"

#include "CoreGameplay/UnrealPatternsPlayerController.h"
#include "Pawns/UnrealPatternsCharacter.h"
#include "UObject/ConstructorHelpers.h"



AUnrealPatternsGameMode::AUnrealPatternsGameMode()
{
	InitializeDefaultCharacterClass();
	
	PlayerControllerClass = AUnrealPatternsPlayerController::StaticClass();
}

void AUnrealPatternsGameMode::InitializeDefaultCharacterClass()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Succeeded())
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else
	{
		DefaultPawnClass = AUnrealPatternsCharacter::StaticClass();
	}
}
