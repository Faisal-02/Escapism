// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectricityGenerator.h"
#include "Components/BoxComponent.h"

// Sets default values
AElectricityGenerator::AElectricityGenerator()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent = SceneComponent;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision-> SetupAttachment(SceneComponent);
	
	GeneratorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	GeneratorMesh->SetupAttachment(SceneComponent);
	GeneratorMesh->SetupAttachment(BoxCollision);
	
	
	
}

// Called when the game starts or when spawned
void AElectricityGenerator::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision -> OnComponentBeginOverlap.AddDynamic(this, &AElectricityGenerator::OnGeneratorBoxTrigger);
	
}

void AElectricityGenerator::OnGeneratorBoxTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//This delegate will handle every things related when player is inside the generator area
	//EX: Show  generator progress bar

	
}



