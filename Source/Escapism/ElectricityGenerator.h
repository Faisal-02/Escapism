// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElectricityGenerator.generated.h"

class ASurvivor;
class AGameEntity;
class UGameHUDWidget;
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
	UPROPERTY(EditAnywhere, Category = "Generator Properties", meta = (ToolTip = "This variable determined the amount of time needed to complete a generator"))
	float TimeToCompleteGenerator;

	UPROPERTY(VisibleAnywhere, Category = "Generator Properties")
	float GeneratorTimeProgression;
	
	bool bIsSurvivorInGeneratorArea = false;

	bool bIsGeneratorDone;

	UPROPERTY(EditDefaultsOnly, Category = "Survivor")
	TSubclassOf<ASurvivor> BPSurvivorClass;
	
	//This TimerHandle will be responsible for Generator Completion Counter
	FTimerHandle GeneratorProgressionTimerHandle;

	
	//-----Pointers-----//

	UPROPERTY(EditAnywhere, Category = "Mesh")
	USceneComponent* SceneComponent;
	
	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* GeneratorMesh;

	UPROPERTY(EditAnywhere, Category = "Collision")
	class UBoxComponent* BoxComp;

	UPROPERTY(VisibleAnywhere, Category = "Run Time")
	AGameEntity* GameEntity;

	UPROPERTY(VisibleAnywhere, Category = "Run Time")
	ASurvivor* Survivor;
	//-----Functions-----//
	UFUNCTION()
	void OnGeneratorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnGeneratorEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void GeneratorDone();
public:
	float GetGeneratorTimeProgression() const;
	bool GetIsSurvivorInGeneratorArea() const;
	FTimerHandle GetGeneratorCompletionTimerHandle() const;
	float CalculateGeneratorProgression();
};
