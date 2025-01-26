// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/Start_UpData_Base.h"
#include "WarrorTypes/Warrior_Struct_Types.h"
#include "Start_Hero_UpData.generated.h"


UCLASS()
class WARIOR_AXE_API UStart_Hero_UpData : public UStart_UpData_Base
{
	GENERATED_BODY()

public:
	virtual void Give_To_AbilitySystem_Component(UWarrior_Ability_System_Component* In_ASCTo_Give, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "Input_Tag"))
	TArray<FWarriorHeroAbilitySet> HeroStartUpAbilitySets;
};
