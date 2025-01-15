// Warior Project Djambulat Tadzhidinov All rights reserved


#include "AnimInstances/Warrior_Character_Anim_Instance.h"
#include "Characters/Warrior_Base_Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UWarrior_Character_Anim_Instance::NativeInitializeAnimation()
{
	Owning_Character = Cast<AWarrior_Base_Character>(TryGetPawnOwner());

	if(Owning_Character)
	{
		Owning_Movement_Component = Owning_Character->GetCharacterMovement();
	}
}
//------------------------------------------------------------------------------------------------------------
void UWarrior_Character_Anim_Instance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if(!Owning_Character || !Owning_Movement_Component)
	{
		return;
	}

	Ground_Speed = Owning_Character->GetVelocity().Size2D();

	bHas_Acceleration = Owning_Movement_Component->GetCurrentAcceleration().SizeSquared2D() > 0.0f;
}
