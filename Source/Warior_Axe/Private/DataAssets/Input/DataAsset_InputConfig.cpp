// Warior Project Djambulat Tadzhidinov All rights reserved


#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::Find_Native_Input_Action_By_Tag(const FGameplayTag& InInputTag) const
{
	for(const FWarriorInputActionConfig& InputActionConfig : Native_Input_Action)
	{
		if(InputActionConfig.Input_Tag == InInputTag && InputActionConfig.Input_Action)
		{
			return InputActionConfig.Input_Action;
		}
	}
	return nullptr;
}
