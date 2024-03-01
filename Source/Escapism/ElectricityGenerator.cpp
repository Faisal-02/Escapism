// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectricityGenerator.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include"GameEntity.h"
#include "GameHUDWidget.h"
#include "Survivor.h"
// Sets default values
AElectricityGenerator::AElectricityGenerator()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent = SceneComponent;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxComp-> SetupAttachment(SceneComponent);
	
	GeneratorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	GeneratorMesh->SetupAttachment(SceneComponent);
	GeneratorMesh->SetupAttachment(BoxComp);

	//Amount of time needed to complete a generator, this maybe override in the editor
	TimeToCompleteGenerator = 10.f;
	//Each gen start with 0 progression
	GeneratorTimeProgression = 0.f;

	
}

// Called when the game starts or when spawned
void AElectricityGenerator::BeginPlay()
{
	Super::BeginPlay();
	//Conect the delegate to the Box Component
	BoxComp -> OnComponentBeginOverlap.AddDynamic(this, &AElectricityGenerator::OnGeneratorBeginOverlap);
	BoxComp -> OnComponentEndOverlap.AddDynamic(this, &AElectricityGenerator::OnGeneratorEndOverlap);
	
	GameEntity = Cast<AGameEntity>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	//This cast has to be change later cuz the GetActorOfClass is return only the first Actor/Character, and the game have more then 1
	//But for now it is okay to use it for test purposes only 
	Survivor = Cast<ASurvivor>(UGameplayStatics::GetActorOfClass(GetWorld(), BPSurvivorClass));

	GetWorld()->GetTimerManager().SetTimer(GeneratorProgressionTimerHandle,this, &AElectricityGenerator::GeneratorDone, TimeToCompleteGenerator, false);
	GetWorld()->GetTimerManager().PauseTimer(GeneratorProgressionTimerHandle);
	
	//When game start there are not any gen is done
	bIsGeneratorDone = false;
}

void AElectricityGenerator::OnGeneratorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Player enter generator area, this var is used by other classes 
	bIsSurvivorInGeneratorArea = true;

	//Check if GameEntity is valid and Generator is not done
	if (GameEntity && bIsGeneratorDone == false)
	{
		//Show progress bar when player enter gen area
		GameEntity -> GetGameHUD()-> ShowGeneratorProgressBar();
	}
	
}

void AElectricityGenerator::OnGeneratorEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//Player left generator area, this var is used by other classes 
	bIsSurvivorInGeneratorArea = false;
	
	if (GameEntity)
	{
		//When player leave gen area hid gen progress bar and pause the timer
		GameEntity -> GetGameHUD()-> HidGeneratorProgressBar();
		GetWorld()->GetTimerManager().PauseTimer(GeneratorProgressionTimerHandle);
	}
	
}

void AElectricityGenerator::GeneratorDone() 
{
	//This will handle any stuff related to the GeneratorDone event
	//EX: Hid Generator Progress Bar when gen is done
	if (GameEntity)
	{
		GameEntity -> GetGameHUD() -> HidGeneratorProgressBar();
		bIsGeneratorDone = true;
	}
	
}


float AElectricityGenerator::CalculateGeneratorProgression()
{
	//This will calculate the gen progress bar percent, and clamp it between 0.0 -> 1.0
	GeneratorTimeProgression = GetWorld()->GetTimerManager().GetTimerElapsed(GeneratorProgressionTimerHandle) / TimeToCompleteGenerator;
	return GeneratorTimeProgression = FMath::Clamp(GeneratorTimeProgression, 0.0f, 1.0f);
}

float AElectricityGenerator::GetGeneratorTimeProgression() const
{
	return GeneratorTimeProgression;
}

bool AElectricityGenerator::GetIsSurvivorInGeneratorArea() const
{
	return bIsSurvivorInGeneratorArea;
}

FTimerHandle AElectricityGenerator::GetGeneratorCompletionTimerHandle() const
{
	return GeneratorProgressionTimerHandle;
}









