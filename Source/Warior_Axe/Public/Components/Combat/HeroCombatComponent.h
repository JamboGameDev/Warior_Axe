// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class AWarrior_Hero_Weapon_Base;
/**
 * 
 */
UCLASS()
class WARIOR_AXE_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarrior_Hero_Weapon_Base* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
	
};
