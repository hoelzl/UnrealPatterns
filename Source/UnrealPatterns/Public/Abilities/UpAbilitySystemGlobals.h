// Copyright Dr. Matthias Hölzl. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "UpAbilitySystemGlobals.generated.h"

/**
 * Global configuration for the ability system
 */
UCLASS()
class UNREALPATTERNS_API UUpAbilitySystemGlobals : public UAbilitySystemGlobals
{
	GENERATED_BODY()

public:
	virtual void InitGlobalData() override;

private:
	UPROPERTY(BlueprintGetter=GetStateAirControlTag)
	FGameplayTag StateAirControlTag;

	UPROPERTY(BlueprintGetter=GetStateDeadTag)
	FGameplayTag StateDeadTag;
	
public:
	UFUNCTION(BlueprintGetter, Category=GameplayTags)
	FGameplayTag GetStateDeadTag() const
	{
		return StateDeadTag;
	}

	UFUNCTION(BlueprintGetter, Category=GameplayTags)
    FGameplayTag GetStateAirControlTag() const
	{
		return StateAirControlTag;
	}
};
