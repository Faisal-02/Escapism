// Fill out your copyright notice in the Description page of Project Settings.


#include "Survivor.h"


void ASurvivor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASurvivor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent -> BindAction("Interaction", IE_Pressed ,this, &ASurvivor::PlayerInteraction);
}

void ASurvivor::PlayerInteraction()
{
	UE_LOG(LogTemp, Warning, TEXT("i am survival class"));
}
