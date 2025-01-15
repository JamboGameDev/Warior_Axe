// Warior Project Djambulat Tadzhidinov All rights reserved


#include "AnimInstances/Hero/Warrior_Hero_Anim_Instance.h"
#include "Characters/Warrior_Hero_Character.h"


//------------------------------------------------------------------------------------------------------------
void UWarrior_Hero_Anim_Instance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if(Owning_Character)
	{
		Owning_Hero_Character = Cast<AWarrior_Hero_Character>(Owning_Character);
	}
}
//------------------------------------------------------------------------------------------------------------
void UWarrior_Hero_Anim_Instance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds); 

	if(bHas_Acceleration)
	{
		Idle_Elapsed_Time = 0.0f;
		bEnter_Relax_State = false;
	}
	else
	{
		Idle_Elapsed_Time += DeltaSeconds;
		bEnter_Relax_State = (Idle_Elapsed_Time >= bTreshold_Relax_State);
	}
}
//------------------------------------------------------------------------------------------------------------