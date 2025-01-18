// Warior Project Djambulat Tadzhidinov All rights reserved


#include "Components/Combat/HeroCombatComponent.h"

#include "Items/Weapons/Warrior_Hero_Weapon_Base.h"

AWarrior_Hero_Weapon_Base* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarrior_Hero_Weapon_Base>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
