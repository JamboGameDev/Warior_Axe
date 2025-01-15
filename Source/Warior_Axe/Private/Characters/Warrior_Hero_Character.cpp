// Warior Project Djambulat Tadzhidinov All rights reserved


#include "Characters/Warrior_Hero_Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/Warrior_Input_Component.h"
#include "Warrior_GamePlay_Tags.h"
#include "AbilitySystem/Warrior_Ability_System_Component.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "DataAssets/StartUpData/Start_Hero_UpData.h"

//------------------------------------------------------------------------------------------------------------
AWarrior_Hero_Character::AWarrior_Hero_Character()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
}
//------------------------------------------------------------------------------------------------------------
void AWarrior_Hero_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartUpData.IsNull())
	{
		if (UStart_UpData_Base* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->Give_To_AbilitySystem_Component(Warrior_Ability_System_Component);
		}
	}
}
//------------------------------------------------------------------------------------------------------------
void AWarrior_Hero_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->Default_Mapping_Context, 0);

	UWarrior_Input_Component* WarriorInputComponent = CastChecked<UWarrior_Input_Component>(PlayerInputComponent);

	WarriorInputComponent->Bind_Native_Input_Action(InputConfigDataAsset, Warrior_GamePlay_Tags::InputTag_Move, ETriggerEvent::Triggered,this, &ThisClass::Input_Move);
	WarriorInputComponent->Bind_Native_Input_Action(InputConfigDataAsset, Warrior_GamePlay_Tags::InputTag_Look, ETriggerEvent::Triggered,this, &ThisClass::Input_Look);

	WarriorInputComponent->Bind_Ability_Input_Action(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
   
}
//------------------------------------------------------------------------------------------------------------
void AWarrior_Hero_Character::BeginPlay()
{
	Super::BeginPlay();

}
//------------------------------------------------------------------------------------------------------------
void AWarrior_Hero_Character::Input_Move(const FInputActionValue& Input_Action_Value)
{
	const FVector2d MovementVector = Input_Action_Value.Get<FVector2D>();

	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if(MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if(MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}
//------------------------------------------------------------------------------------------------------------
void AWarrior_Hero_Character::Input_Look(const FInputActionValue& Input_Action_Value)
{
	const FVector2d LookAxisVector = Input_Action_Value.Get<FVector2D>();

	if(LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if(LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}

}
//------------------------------------------------------------------------------------------------------------
void AWarrior_Hero_Character::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	Warrior_Ability_System_Component->OnAbilityInputPressed(InInputTag);
}
//------------------------------------------------------------------------------------------------------------
void AWarrior_Hero_Character::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	Warrior_Ability_System_Component->OnAbilityInputReleased(InInputTag);
}
//------------------------------------------------------------------------------------------------------------
