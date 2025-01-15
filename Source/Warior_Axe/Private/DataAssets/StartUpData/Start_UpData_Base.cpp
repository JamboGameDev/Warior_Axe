// Warior Project Djambulat Tadzhidinov All rights reserved


#include "DataAssets/StartUpData/Start_UpData_Base.h"
#include "AbilitySystem/Warrior_Ability_System_Component.h"
#include "AbilitySystem/Abilities/Warrior_Gameplay_Ability.h"
//---------------------------------------------------------------------------------------------------------------------
void UStart_UpData_Base::Give_To_AbilitySystem_Component(UWarrior_Ability_System_Component* In_ASCTo_Give, int32 ApplyLevel)
{
	check(In_ASCTo_Give);

	Grand_Abilities(Activate_OnGiven_Abilities, In_ASCTo_Give, ApplyLevel);
	Grand_Abilities(Reactive_Ablities, In_ASCTo_Give, ApplyLevel);

}
//---------------------------------------------------------------------------------------------------------------------
void UStart_UpData_Base::Grand_Abilities(TArray<TSubclassOf<UWarrior_Gameplay_Ability>>& InAbilities_To_Give, UWarrior_Ability_System_Component* In_ASCTo_Give, int32 ApplyLevel)
{
	if(InAbilities_To_Give.IsEmpty())
	{
		return;
	}

	for(const TSubclassOf<UWarrior_Gameplay_Ability>& Ability : InAbilities_To_Give)
	{
		if (!Ability) continue;
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = In_ASCTo_Give->GetAvatarActor();

		In_ASCTo_Give->GiveAbility(AbilitySpec);
	}

}
//---------------------------------------------------------------------------------------------------------------------
