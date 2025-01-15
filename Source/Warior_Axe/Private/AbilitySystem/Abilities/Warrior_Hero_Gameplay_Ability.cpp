// Warior Project Djambulat Tadzhidinov All rights reserved


#include "AbilitySystem/Abilities/Warrior_Hero_Gameplay_Ability.h"
#include "Characters/Warrior_Hero_Character.h"
#include "Controllers/Warrior_Controllers.h"

AWarrior_Hero_Character* UWarrior_Hero_Gameplay_Ability::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		CachedWarriorHeroCharacter = Cast<AWarrior_Hero_Character>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedWarriorHeroCharacter.IsValid() ? CachedWarriorHeroCharacter.Get() : nullptr;
	
}
//------------------------------------------------------------------------------------------------------------------
AWarrior_Controllers* UWarrior_Hero_Gameplay_Ability::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<AWarrior_Controllers>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedWarriorHeroController.IsValid() ? CachedWarriorHeroController.Get() : nullptr;
}
//------------------------------------------------------------------------------------------------------------------
UHeroCombatComponent* UWarrior_Hero_Gameplay_Ability::GetHeroCombatComponentFromActorInfo()
{
	 return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
//------------------------------------------------------------------------------------------------------------------
