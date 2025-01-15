// Warior Project Djambulat Tadzhidinov All rights reserved

#pragma once

#include "NativeGameplayTags.h"

namespace Warrior_GamePlay_Tags
{

	/** INPUT TAGS **/
	WARIOR_AXE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move)
	WARIOR_AXE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)
	WARIOR_AXE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe)
	WARIOR_AXE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequippedAxe)

	/**Player tags**/
	WARIOR_AXE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	
	WARIOR_AXE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	WARIOR_AXE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquip_Axe);

}
