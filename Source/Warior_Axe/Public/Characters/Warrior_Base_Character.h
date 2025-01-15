// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Warrior_Base_Character.generated.h"


class UWarrior_Ability_System_Component;
class UWarrior_Attribute_Set;
class UStart_UpData_Base;

UCLASS()
class WARIOR_AXE_API AWarrior_Base_Character : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarrior_Base_Character();

	//~ Begin AbilitySystemInterface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End AbilitySystemInterface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UWarrior_Ability_System_Component* Warrior_Ability_System_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UWarrior_Attribute_Set* Warrior_Attribute_Set;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UStart_UpData_Base> CharacterStartUpData;

public:
	FORCEINLINE UWarrior_Ability_System_Component* GetWarriorAbilitySystemComponent() const { return Warrior_Ability_System_Component; }

	FORCEINLINE UWarrior_Attribute_Set* GetWarriorAttributeSet() const { return Warrior_Attribute_Set; }
};
