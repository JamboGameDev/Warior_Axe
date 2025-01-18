// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/Warrior_Base_Anim_Instance.h"
#include "Warrior_Hero_Linked_Anim_Layer.generated.h"

class UWarrior_Hero_Anim_Instance;
/**
 * 
 */
UCLASS()
class WARIOR_AXE_API UWarrior_Hero_Linked_Anim_Layer : public UWarrior_Base_Anim_Instance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UWarrior_Hero_Anim_Instance* GetHeroAnim_Instance() const;
	
};
