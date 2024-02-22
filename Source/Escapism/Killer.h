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

virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	//-----Variables-----//
	
	
	//-----Pointers-----//

	//-----Functions-----//

	virtual void PlayerInteraction() override;

	
};
