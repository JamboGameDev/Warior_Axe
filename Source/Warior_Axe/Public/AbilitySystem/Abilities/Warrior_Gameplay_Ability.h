// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Warrior_Gameplay_Ability.generated.h"

class UPawnCombatComponent;
class UWarrior_Ability_System_Component;

UENUM(BlueprintType)
enum class EWarriorAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};
UCLASS()
class WARIOR_AXE_API UWarrior_Gameplay_Ability : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin GameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End GameplayAbility Interface.

	UPROPERTY(EditDefaultsOnly, Category = "WarriorAbility")
	EWarriorAbilityActivationPolicy AbilityActivationPolicy = EWarriorAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UWarrior_Ability_System_Component* GetWarriorAbilitySystemComponentFromActorInfo() const;
};
