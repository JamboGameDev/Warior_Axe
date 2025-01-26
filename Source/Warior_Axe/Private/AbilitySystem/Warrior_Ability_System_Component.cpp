// Warior Project Djambulat Tadzhidinov All rights reserved


#include "AbilitySystem/Warrior_Ability_System_Component.h"
#include "AbilitySystem/Abilities/Warrior_Gameplay_Ability.h"

//-------------------------------------------------------------------------------------------------------------
void UWarrior_Ability_System_Component::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	 if (!InInputTag.IsValid())
	 {
		 return;
	 }

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;
		TryActivateAbility(AbilitySpec.Handle);
	}
	
}
//------------------------------------------------------------------------------------------------------------
void UWarrior_Ability_System_Component::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
	
}
//-------------------------------------------------------------------------------------------------------------
void UWarrior_Ability_System_Component::GrantHeroWeaponAbilities(
	const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantAbilitySpecHandless)
{
	if (InDefaultWeaponAbilities.IsEmpty())
	{
		return;
	}

	for (const FWarriorHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec (AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.Input_Tag);

		OutGrantAbilitySpecHandless.AddUnique(GiveAbility(AbilitySpec));
	}
}
//-------------------------------------------------------------------------------------------------------------
void UWarrior_Ability_System_Component::RemovedGrantedHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove)
{
	if (InSpecHandlesToRemove.IsEmpty())
	{
		return;
	}

	for (const FGameplayAbilitySpecHandle& SpecHandle : InSpecHandlesToRemove)
	{
		if (SpecHandle.IsValid())
		{
			// Дополнительная проверка, если требуется
			if (FindAbilitySpecFromHandle(SpecHandle)) 
			{
				ClearAbility(SpecHandle);
			}
		}
	}

	// Очистку массива оставьте на усмотрение вызывающей функции
	InSpecHandlesToRemove.Empty();
}
//-------------------------------------------------------------------------------------------------------------
