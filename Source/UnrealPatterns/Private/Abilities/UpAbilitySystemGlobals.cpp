// Copyright Dr. Matthias Hölzl. All Rights Reserved.

#include "Abilities/UpAbilitySystemGlobals.h"

void UUpAbilitySystemGlobals::InitGlobalData()
{
	StateAirControlTag = FGameplayTag::RequestGameplayTag("State.AirControl");
	StateDeadTag = FGameplayTag::RequestGameplayTag("State.Dead");
}
