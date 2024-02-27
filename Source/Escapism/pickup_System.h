// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include"GameEntity.h"
#include "CoreMinimal.h"
#include "item.h"
#include "GameFramework/Actor.h"
#include "pickup_System.generated.h"




UCLASS()
class ESCAPISM_API Apickup_System : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Apickup_System();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	
	UPROPERTY(EditAnywhere, Category = "Mesh")
	USceneComponent* SceneComponent;
	
	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* GeneratorMesh;

	UPROPERTY(EditAnywhere, Category = "Collision")
	class UBoxComponent* BoxComp;

	UPROPERTY(VisibleAnywhere, Category = "Run Time")
	AGameEntity* GameEntity;
	// item store system
	TArray<UClass> StorageArr[2];
	TQueue<UClass> Storagequ;
	TArray<AActor*> Storagevariable[1]; 
	
	UFUNCTION()
	void OnITemBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);


	UFUNCTION()
	void OnItemEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
	void ownergetting();
};
