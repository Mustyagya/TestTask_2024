// RedRuins Softworks (c)


#include "Task_01_Actor.h"

// Sets default values
ATask_01_Actor::ATask_01_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	Actor_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	Actor_Mesh->SetupAttachment(RootComponent);


	static ConstructorHelpers::FObjectFinder<UMaterialInterface>DefaultMat(TEXT("Material'/Engine/MapTemplates/Materials/BasicAsset03.BasicAsset03'"));
    if (DefaultMat.Succeeded())
    {
        DefaultMaterial = DefaultMat.Object;
    }
    else
    {
        // Если материал не был найден, выведите предупреждение
        UE_LOG(LogTemp, Warning, TEXT("Default material not found"));
    }

    Actor_Mesh->OnComponentBeginOverlap.AddDynamic(this, &ATask_01_Actor::OnBeginOverlap);
}

// Called when the game starts or when spawned
void ATask_01_Actor::BeginPlay()
{
    Super::BeginPlay();

    if (DefaultMaterial)
    {
        Actor_Mesh->SetMaterial(0, DefaultMaterial);
    }
    else
    {
        // Если дефолтный материал не был найден, выведите предупреждение
        UE_LOG(LogTemp, Warning, TEXT("Default material not set"));
    }
}

// Called every frame
void ATask_01_Actor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATask_01_Actor::OnBeginOverlap(UPrimitiveComponent* OverlappedComp,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult)
{
    ATask_01_Character* MyCharacter = Cast<ATask_01_Character>(OtherActor);
    if (MyCharacter)
    {
        // Проверяем, есть ли у компонента материал и изменяем его цвет
        if (Actor_Mesh)
        {
            UMaterialInstanceDynamic* DynamicMaterial = Cast<UMaterialInstanceDynamic>(Actor_Mesh->GetMaterial(0));
            if (DynamicMaterial)
            {
                // Устанавливаем новый цвет для параметра Base Color
                DynamicMaterial->SetVectorParameterValue(TEXT("BaseColor"), FLinearColor(1.0f, 0.0f, 0.0f)); // Красный цвет
            }
            else
            {
                // Если материал не динамический, создаем его динамическую копию и устанавливаем цвет
                UMaterialInterface* Material = Actor_Mesh->GetMaterial(0);
                if (Material)
                {
                    DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
                    if (DynamicMaterial)
                    {
                        DynamicMaterial->SetVectorParameterValue(TEXT("BaseColor"), FLinearColor(1.0f, 0.0f, 0.0f)); // Красный цвет
                        Actor_Mesh->SetMaterial(0, DynamicMaterial);
                    }
                }
            }
        }
        else
        {
            // Выводим предупреждение, если компонент не найден
            UE_LOG(LogTemp, Warning, TEXT("Mesh component not found"));
        }
    }
}