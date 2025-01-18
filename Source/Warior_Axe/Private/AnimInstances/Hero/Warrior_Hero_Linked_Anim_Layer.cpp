// Warior Project Djambulat Tadzhidinov All rights reserved


#include "AnimInstances/Hero/Warrior_Hero_Linked_Anim_Layer.h"
#include "AnimInstances/Hero/Warrior_Hero_Anim_Instance.h"

UWarrior_Hero_Anim_Instance* UWarrior_Hero_Linked_Anim_Layer::GetHeroAnim_Instance() const
{
	return Cast<UWarrior_Hero_Anim_Instance>(GetOwningComponent()->GetAnimInstance());
}
//------------------------------------------------------------------------------------------