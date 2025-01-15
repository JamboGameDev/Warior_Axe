// Warior Project Djambulat Tadzhidinov All rights reserved


#include "Items/Weapons/Warrior_Weapon_Base.h"
#include "Components/BoxComponent.h"

// Sets default values
AWarrior_Weapon_Base::AWarrior_Weapon_Base()
{

	PrimaryActorTick.bCanEverTick = false;

	Weapon_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(Weapon_Mesh);

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));

	WeaponCollisionBox->SetupAttachment(GetRootComponent());

	WeaponCollisionBox->SetBoxExtent(FVector(20.f));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

