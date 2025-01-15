// Warior Project Djambulat Tadzhidinov All rights reserved


#include "Characters/Warrior_Base_Character.h"
#include "AbilitySystem/Warrior_Ability_System_Component.h"
#include "AbilitySystem/Warrior_Attribute_Set.h"

// Sets default values
AWarrior_Base_Character::AWarrior_Base_Character()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	Warrior_Ability_System_Component = CreateDefaultSubobject<UWarrior_Ability_System_Component>(TEXT("Warrior_Ability_System_Component"));

	Warrior_Attribute_Set = CreateDefaultSubobject<UWarrior_Attribute_Set>(TEXT("Warrior_Attribute_Set"));
}
//------------------------------------------------------------------------------------------------------------
UAbilitySystemComponent* AWarrior_Base_Character::GetAbilitySystemComponent() const
{
	return GetWarriorAbilitySystemComponent();
}
//------------------------------------------------------------------------------------------------------------
void AWarrior_Base_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(Warrior_Ability_System_Component)
	{
		Warrior_Ability_System_Component->InitAbilityActorInfo(this, this);
		
		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}


