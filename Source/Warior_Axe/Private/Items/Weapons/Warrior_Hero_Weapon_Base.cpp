// Warior Project Djambulat Tadzhidinov All rights reserved


#include "Items/Weapons/Warrior_Hero_Weapon_Base.h"

//-----------------------------------------------------------------------------------------------------------------------------
void AWarrior_Hero_Weapon_Base::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedAbilitySpecHandles = InSpecHandles;
}
//-----------------------------------------------------------------------------------------------------------------------------
TArray<FGameplayAbilitySpecHandle> AWarrior_Hero_Weapon_Base::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}
//-----------------------------------------------------------------------------------------------------------------------------

