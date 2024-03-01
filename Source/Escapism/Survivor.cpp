// Fill out your copyright notice in the Description page of Project Settings.


#include "Survivor.h"

#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "ElectricityGenerator.h"
#include "GameHUDWidget.h"

void ASurvivor::BeginPlay()
{
	Super::BeginPlay();

	//Get survivor controller and add the input action context
	SurvivorController = UGameplayStatics::GetPlayerController(this, 0);
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(SurvivorController -> GetLocalPlayer()))
	{
		Subsystem -> AddMappingContext(PlayerMappingContext, 0);
	}

	//This cast has to be change later cuz the GetActorOfClass is return only the first Actor/Character, and the game have more then 1
	//But for now it is okay to use it for test purposes only 
	ElectricityGenerator = Cast<AElectricityGenerator>(UGameplayStatics::GetActorOfClass(GetWorld(), BPElectricityGeneratorClass));
}


void ASurvivor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Bind Actions
		EnhancedInputComponent->BindAction(InteractingHoldAction, ETriggerEvent::Triggered, this, &ASurvivor::InteractWithGenerator);
		EnhancedInputComponent->BindAction(InteractingReleasedAction, ETriggerEvent::Completed, this, &ASurvivor::StopInteractWithGenerator);
	}
}

void ASurvivor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ASurvivor::InteractWithGenerator(const FInputActionValue& Value)
{
	if (ElectricityGenerator)
	{
		//Check if Survivor in gen area and Holding Interaction Button
		if (ElectricityGenerator -> GetIsSurvivorInGeneratorArea() == true)
		{
			//The timer will start
			//calculate the GeneratorProgression
			//Set GeneratorProgressBarPercent
			GetWorld()->GetTimerManager().UnPauseTimer(ElectricityGenerator->GetGeneratorCompletionTimerHandle());
			const float GeneratorProgression = ElectricityGenerator -> CalculateGeneratorProgression();
			GameHUDWidget -> SetGeneratorProgressBarPercent(GeneratorProgression);

		}
		
	}

}

void ASurvivor::StopInteractWithGenerator(const FInputActionValue& Value)
{
	//Check if Survivor Released Interaction Button
	if (ElectricityGenerator)
	{
		//Timer will Pause
		GetWorld()->GetTimerManager().PauseTimer(ElectricityGenerator->GetGeneratorCompletionTimerHandle());
	}
}
