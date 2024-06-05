// RedRuins Softworks (c)


#include "Task_01_Character.h"

// Sets default values
ATask_01_Character::ATask_01_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATask_01_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATask_01_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATask_01_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

