// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once
#include "Warrior_Struct_Types.generated.h"

class UWarrior_Hero_Linked_Anim_Layer;

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarrior_Hero_Linked_Anim_Layer> WeaponAnimLayerToLink;
};
