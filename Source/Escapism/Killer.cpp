// Fill out your copyright notice in the Description page of Project Settings.


#include "Killer.h"

void AKiller::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent -> BindAction("Interaction", IE_Pressed ,this, &AKiller::PlayerInteraction);
}

void AKiller::PlayerInteraction()
{
	UE_LOG(LogTemp, Warning, TEXT("i am Killer class"));
}
