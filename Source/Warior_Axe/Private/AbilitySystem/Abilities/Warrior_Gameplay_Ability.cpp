// Warior Project Djambulat Tadzhidinov All rights reserved


#include "AbilitySystem/Abilities/Warrior_Gameplay_Ability.h"
#include "AbilitySystem/Warrior_Ability_System_Component.h"
#include "Components/Combat/PawnCombatComponent.h"

void UWarrior_Gameplay_Ability::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if(AbilityActivationPolicy == EWarriorAbilityActivationPolicy::OnGiven)
	{
		if(ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}
//--------------------------------------------------------------------------------------------------------------------------
void UWarrior_Gameplay_Ability::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if(ActorInfo)
	{
		ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
	}
}
//--------------------------------------------------------------------------------------------------------------------------
UPawnCombatComponent* UWarrior_Gameplay_Ability::GetPawnCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}
//--------------------------------------------------------------------------------------------------------------------------
UWarrior_Ability_System_Component* UWarrior_Gameplay_Ability::GetWarriorAbilitySystemComponentFromActorInfo() const
{
	return Cast<UWarrior_Ability_System_Component>(CurrentActorInfo->AbilitySystemComponent);
}
//--------------------------------------------------------------------------------------------------------------------------
