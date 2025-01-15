// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Start_UpData_Base.generated.h"

class UWarrior_Gameplay_Ability;
class UWarrior_Ability_System_Component;

UCLASS()
class WARIOR_AXE_API UStart_UpData_Base : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void Give_To_AbilitySystem_Component(UWarrior_Ability_System_Component* In_ASCTo_Give, int32 ApplyLevel = 1);
	
protected:
	

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray <TSubclassOf	< UWarrior_Gameplay_Ability > > Activate_OnGiven_Abilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray <TSubclassOf	< UWarrior_Gameplay_Ability > > Reactive_Ablities;

	void Grand_Abilities(TArray <TSubclassOf < UWarrior_Gameplay_Ability > >& InAbilities_To_Give, UWarrior_Ability_System_Component* In_ASCTo_Give, int32 ApplyLevel = 1);

};
