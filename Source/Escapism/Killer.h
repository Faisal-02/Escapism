// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEntity.h"
#include "Killer.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPISM_API AKiller : public AGameEntity
{
	GENERATED_BODY()
virtual void BeginPlay() override;
	//-----Variables-----//
	
	
	//-----Pointers-----//
	
	UPROPERTY(VisibleAnywhere)	
	APlayerController* KillerController;

	
	//-----Functions-----//

	virtual void InteractWithGenerator(const FInputActionValue& Value) override;

	
};
