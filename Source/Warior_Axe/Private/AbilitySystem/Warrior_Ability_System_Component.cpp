// Warior Project Djambulat Tadzhidinov All rights reserved


#include "AbilitySystem/Warrior_Ability_System_Component.h"

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