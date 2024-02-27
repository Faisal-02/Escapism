// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEntity.h"
#include "Survivor.generated.h"


UCLASS()
class ESCAPISM_API ASurvivor : public AGameEntity
{
	GENERATED_BODY()

	virtual void BeginPlay() override;


private:
	//-----Variables-----//
	
	
	//-----Pointers-----//
	
	UPROPERTY(VisibleAnywhere)	
	APlayerController* SurvivorController;
	
	//-----Functions-----//

	virtual void PlayerInteraction(const FInputActionValue& Value) override;


	
};
