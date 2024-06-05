// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Task_01_Character.generated.h"

UCLASS()
class TESTTASK_2024_API ATask_01_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATask_01_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
