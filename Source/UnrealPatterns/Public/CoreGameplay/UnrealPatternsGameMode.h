// Copyright Dr. Matthias Hölzl. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealPatternsGameMode.generated.h"

UCLASS(minimalapi)
class AUnrealPatternsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealPatternsGameMode();

private:
	void InitializeDefaultCharacterClass();
};
