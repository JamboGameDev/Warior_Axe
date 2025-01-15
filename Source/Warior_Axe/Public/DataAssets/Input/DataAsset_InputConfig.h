// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag Input_Tag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Input_Action;
	
	bool IsValid() const
	{
		return Input_Tag.IsValid() && Input_Action;
	}
};
//------------------------------------------------------------------------------------------------------------
UCLASS()
class WARIOR_AXE_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* Default_Mapping_Context;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "Input_Tag"))
	TArray<FWarriorInputActionConfig> Native_Input_Action;

	UInputAction* Find_Native_Input_Action_By_Tag(const FGameplayTag& InInputTag) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "Input_Tag"))
	TArray<FWarriorInputActionConfig> AbilityInputActions;
};
