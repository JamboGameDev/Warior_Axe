// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/Warrior_Weapon_Base.h"
#include "WarrorTypes/Warrior_Struct_Types.h"
#include "Warrior_Hero_Weapon_Base.generated.h"

/**
 * 
 */
UCLASS()
class WARIOR_AXE_API AWarrior_Hero_Weapon_Base : public AWarrior_Weapon_Base
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponsData")
	FWarriorHeroWeaponData HeroWeaponData;
	
	
};
