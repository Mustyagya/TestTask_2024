// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h" 
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h" 
#include  "GameFramework/Actor.h"
#include "Task_01_Character.h"
#include "Task_01_Actor.generated.h"

UCLASS()
class TESTTASK_2024_API ATask_01_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATask_01_Actor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly) UMaterialInterface* DefaultMaterial;
	//UPROPERTY(EditDefaultsOnly) UMaterialInterface* ChangeMaterial;

private:
	 USceneComponent* RootComponent;
	UStaticMeshComponent* Actor_Mesh;

	UFUNCTION() void OnBeginOverlap
	(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
