// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once
#include "GameplayTagContainer.h"
#include "Warrior_Struct_Types.generated.h"

class UWarrior_Hero_Linked_Anim_Layer;
class UWarrior_Gameplay_Ability;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWarriorHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag Input_Tag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarrior_Gameplay_Ability> AbilityToGrant;

	bool IsValid() const;
	
};

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarrior_Hero_Linked_Anim_Layer> WeaponAnimLayerToLink;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "Input_Tag"))
	TArray<FWarriorHeroAbilitySet> DefaultWeaponAbilities;
};
