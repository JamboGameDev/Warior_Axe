// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DataAssets/StartUpData/Start_UpData_Base.h"
#include "Start_Hero_UpData.generated.h"


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
