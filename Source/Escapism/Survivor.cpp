// Fill out your copyright notice in the Description page of Project Settings.


#include "Survivor.h"

#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"


void ASurvivor::BeginPlay()
{
	Super::BeginPlay();

	SurvivorController = UGameplayStatics::GetPlayerController(this, 0);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(SurvivorController -> GetLocalPlayer()))
	{
		Subsystem -> AddMappingContext(PlayerMappingContext, 0);
	}
	
	
}

void ASurvivor::PlayerInteraction(const FInputActionValue& Value)
{
	
}



