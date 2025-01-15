// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/Warrior_Character_Anim_Instance.h"
#include "Warrior_Hero_Anim_Instance.generated.h"

class AWarrior_Hero_Character;
//------------------------------------------------------------------------------------------------------------
UCLASS()
class WARIOR_AXE_API UWarrior_Hero_Anim_Instance : public UWarrior_Character_Anim_Instance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refetences")
	AWarrior_Hero_Character* Owning_Hero_Character;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bEnter_Relax_State;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float bTreshold_Relax_State = 5.0f;
	
	float Idle_Elapsed_Time;
	
};
