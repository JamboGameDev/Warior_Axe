// Warior Project Djambulat Tadzhidinov All rights reserved


#include "DataAssets/StartUpData/Start_Hero_UpData.h"

#include "AbilitySystem/Warrior_Ability_System_Component.h"
#include "AbilitySystem/Abilities/Warrior_Gameplay_Ability.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return Input_Tag.IsValid() && AbilityToGrant;
}
//---------------------------------------------------------------------------------------------------------------
void UStart_Hero_UpData::Give_To_AbilitySystem_Component(UWarrior_Ability_System_Component* In_ASCTo_Give,
	int32 ApplyLevel)
{
	Super::Give_To_AbilitySystem_Component(In_ASCTo_Give, ApplyLevel);

	for (const FWarriorHeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = In_ASCTo_Give->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.Input_Tag);

		In_ASCTo_Give->GiveAbility(AbilitySpec);
	}
	
}
