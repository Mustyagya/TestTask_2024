// RedRuins Softworks (c)

#include "ActorsComponent.h"

// Sets default values for this component's properties
UActorsComponent::UActorsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	
	Actor_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	Actor_Mesh->SetupAttachment(RootComponent);


	static ConstructorHelpers::FObjectFinder<UMaterialInterface>DefaultMat(TEXT("Material'/Engine/MapTemplates/Materials/BasicAsset03.BasicAsset03'"));
	if (DefaultMat.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("Material change: %s"), *DefaultMat.Object->GetName());
		
		DefaultMaterial = DefaultMat.Object;
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface>ChangeMat(TEXT("Material'/Engine/EngineDebugMaterials/HeatmapMaterial.HeatmapMaterial'"));
	if (ChangeMat.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("Material change: %s"), *ChangeMat.Object->GetName());
		ChangeMaterial = ChangeMat.Object;
	}
    
	Actor_Mesh->OnComponentBeginOverlap.AddDynamic(this, &UActorsComponent::OnBeginOverlap);

}




// Called when the game starts
void UActorsComponent::BeginPlay()
{
	Super::BeginPlay();

	if (DefaultMaterial)
	{
		Actor_Mesh->SetMaterial(0, DefaultMaterial);
	}

	
	
}


// Called every frame
void UActorsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UActorsComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATask_01_Character* MyCharacter = Cast<ATask_01_Character>(OtherActor);
	if (MyCharacter)
	{
		if (ChangeMaterial)
		{
			FString DebugMessage = FString::Printf(TEXT("Collision detected with %s"), *OtherActor->GetName());
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, DebugMessage);

			Actor_Mesh->SetMaterial(0, ChangeMaterial);
		}
	}

	
}



