// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "Abilities/GameplayAbility.h"
#include "CoreMinimal.h"
#include "GA_IncrementSpyValue.generated.h"

/**
 * TODO
 */
UCLASS()
class SPATIALGDKFUNCTIONALTESTS_API UGA_IncrementSpyValue : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_IncrementSpyValue();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
								 const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};