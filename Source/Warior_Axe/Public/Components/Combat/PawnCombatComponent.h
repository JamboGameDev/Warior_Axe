// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

class AWarrior_Weapon_Base;

UCLASS()
class WARIOR_AXE_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void RegisterSpawnedWeapon (FGameplayTag InWeaponTagToRegister, AWarrior_Weapon_Base* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false); 

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarrior_Weapon_Base* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarrior_Weapon_Base* GetCharacterCurrentEquippedWeapon() const;

private:
	TMap<FGameplayTag, AWarrior_Weapon_Base*> CharacterCarriedWeaponMap;
	
};
