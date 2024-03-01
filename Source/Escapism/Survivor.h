// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEntity.h"
#include "Survivor.generated.h"


class AElectricityGenerator;

UCLASS()
class ESCAPISM_API ASurvivor : public AGameEntity
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
virtual void Tick(float DeltaSeconds) override;
private:
	//-----Variables-----//

	//This check if player pressing Interaction Button
	

	UPROPERTY(EditDefaultsOnly, Category = "Generator")
	TSubclassOf<AElectricityGenerator> BPElectricityGeneratorClass;
	
	//-----Pointers-----//
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")	
	UInputAction* InteractingHoldAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")	
	UInputAction* InteractingReleasedAction;

	UPROPERTY(VisibleAnywhere, Category = "Run Time")
	APlayerController* SurvivorController;
	
	UPROPERTY(VisibleAnywhere, Category = "Run Time")
	AElectricityGenerator* ElectricityGenerator;
	
	//-----Functions-----//

	virtual void InteractWithGenerator(const FInputActionValue& Value) override;
	virtual void StopInteractWithGenerator(const FInputActionValue& Value) override;
	
	
};
