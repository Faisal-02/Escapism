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
	
	
	
}

// Called when the game starts or when spawned
void AElectricityGenerator::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp -> OnComponentBeginOverlap.AddDynamic(this, &AElectricityGenerator::OnGeneratorBeginOverlap);
	BoxComp -> OnComponentEndOverlap.AddDynamic(this, &AElectricityGenerator::OnGeneratorEndOverlap);
	
	GameEntity = Cast<AGameEntity>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void AElectricityGenerator::OnGeneratorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//This delegate will handle every things related when player is inside the generator area
	//EX: Show  generator progress bar

	if (GameEntity)
	{
		GameEntity -> GetGameHUD()-> ShowGeneratorProgressBar();
	}
	
}

void AElectricityGenerator::OnGeneratorEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GameEntity)
	{
		GameEntity -> GetGameHUD()-> HidGeneratorProgressBar();
	}
}









