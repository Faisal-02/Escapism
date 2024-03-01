// Fill out your copyright notice in the Description page of Project Settings.


#include "pickup_System.h"
#include "ElectricityGenerator.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include"GameEntity.h"
#include "GameHUDWidget.h"
#include "item.h"
#include "Survivor.h"


// Sets default values
Apickup_System::Apickup_System()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent = SceneComponent;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxComp-> SetupAttachment(SceneComponent);
	
	GeneratorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	GeneratorMesh->SetupAttachment(SceneComponent);
	GeneratorMesh->SetupAttachment(BoxComp);
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Apickup_System::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp -> OnComponentBeginOverlap.AddDynamic(this, &Apickup_System::OnITemBeginOverlap);
 	BoxComp -> OnComponentEndOverlap.AddDynamic(this, &Apickup_System::OnItemEndOverlap);
	
	GameEntity = Cast<AGameEntity>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
}

// Called every frame
void Apickup_System::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Apickup_System::OnITemBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//This delegate will handle every things related when player is inside the generator area
	//EX: Show  generator progress bar

	if (GameEntity)
	{
		//to deltete the mesh 
		Destroy();
		if(Storagevariable!=nullptr)
		{
			 
			
		}
		
	}
	
}

void Apickup_System::OnItemEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GameEntity)
	{
		
	}
}
void Apickup_System::ownergetting()
{
	GetOwner();
}
