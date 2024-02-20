// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElectricityGenerator.generated.h"


UCLASS()
class ESCAPISM_API AElectricityGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElectricityGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



private:
	//-----Variables-----//
	
	//-----Pointers-----//

	UPROPERTY(EditAnywhere, Category = "Mesh")
	USceneComponent* SceneComponent;
	
	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* GeneratorMesh;

	UPROPERTY(EditAnywhere, Category = "Collision")
	class UBoxComponent* BoxCollision;
	
	//-----Functions-----//
	UFUNCTION()
	void OnGeneratorBoxTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	
};
