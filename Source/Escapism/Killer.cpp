// Fill out your copyright notice in the Description page of Project Settings.


#include "Killer.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"


void AKiller::BeginPlay()
{
	Super::BeginPlay();
	
	KillerController = UGameplayStatics::GetPlayerController(this, 0);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(KillerController -> GetLocalPlayer()))
	{
		Subsystem -> AddMappingContext(PlayerMappingContext, 0);
	}
}

void AKiller::InteractWithGenerator(const FInputActionValue& Value)
{

}
