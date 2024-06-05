// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h" 
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h" 
#include "Task_01_Character.h"
#include "ActorsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTTASK_2024_API UActorsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorsComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditDefaultsOnly) UMaterialInterface* DefaultMaterial;
	UPROPERTY(EditDefaultsOnly) UMaterialInterface* ChangeMaterial;

private:
	UPROPERTY() USceneComponent* RootComponent;
	UPROPERTY()UStaticMeshComponent* Actor_Mesh;

	UFUNCTION() void OnBeginOverlap
	(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;		
};
