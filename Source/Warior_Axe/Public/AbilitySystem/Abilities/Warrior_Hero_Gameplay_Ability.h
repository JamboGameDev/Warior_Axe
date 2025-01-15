// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/Warrior_Gameplay_Ability.h"
#include "Warrior_Hero_Gameplay_Ability.generated.h"

class AWarrior_Hero_Character;
class AWarrior_Controllers;
class UHeroCombatComponent;

UCLASS()
class WARIOR_AXE_API UWarrior_Hero_Gameplay_Ability : public UWarrior_Gameplay_Ability
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarrior_Hero_Character* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarrior_Controllers* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
	
private:
	TWeakObjectPtr<AWarrior_Hero_Character> CachedWarriorHeroCharacter;
	TWeakObjectPtr<AWarrior_Controllers> CachedWarriorHeroController;
};
