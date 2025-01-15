// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/Warrior_Base_Anim_Instance.h"
#include "Warrior_Character_Anim_Instance.generated.h"


class AWarrior_Base_Character;
class UCharacterMovementComponent;

UCLASS()
class WARIOR_AXE_API UWarrior_Character_Anim_Instance : public UWarrior_Base_Anim_Instance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	AWarrior_Base_Character* Owning_Character;

	UPROPERTY()
	UCharacterMovementComponent* Owning_Movement_Component;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float Ground_Speed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHas_Acceleration; 

};
