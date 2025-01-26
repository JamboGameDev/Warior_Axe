// Warior Project Djambulat Tadzhidinov All rights reserved


#include "WarrorTypes/Warrior_Struct_Types.h"
#include "AbilitySystem/Abilities/Warrior_Gameplay_Ability.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return  Input_Tag.IsValid() && AbilityToGrant;
}
