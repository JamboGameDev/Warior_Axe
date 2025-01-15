// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Warrior_Input_Component.generated.h"


UCLASS()
class WARIOR_AXE_API UWarrior_Input_Component : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void Bind_Native_Input_Action(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);

	template<class UserObject, typename CallbackFunc>
	void Bind_Ability_Input_Action(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressFunc, CallbackFunc InputReleaseFunc);
	
};
//------------------------------------------------------------------------------------------------------------
template<class UserObject, typename CallbackFunc>
inline void UWarrior_Input_Component::Bind_Native_Input_Action(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input confi g data is null, can not proceed with binding"));

	if(UInputAction* FoundAction = InInputConfig->Find_Native_Input_Action_By_Tag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}
//------------------------------------------------------------------------------------------------------------
template <class UserObject, typename CallbackFunc>
inline void UWarrior_Input_Component::Bind_Ability_Input_Action(const UDataAsset_InputConfig* InInputConfig,
	UserObject* ContextObject, CallbackFunc InputPressFunc, CallbackFunc InputReleaseFunc)
{
	checkf(InInputConfig, TEXT("Input config data is null, can not proceed with binding"));

	for (const FWarriorInputActionConfig& AbilityInputActionConfig : InInputConfig->AbilityInputActions)
	{
		if (!AbilityInputActionConfig.IsValid()) continue;
		BindAction(AbilityInputActionConfig.Input_Action, ETriggerEvent::Started, ContextObject, InputPressFunc, AbilityInputActionConfig.Input_Tag);
		BindAction(AbilityInputActionConfig.Input_Action, ETriggerEvent::Completed, ContextObject, InputReleaseFunc, AbilityInputActionConfig.Input_Tag);
	}
}
