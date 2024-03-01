// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDWidget.h"
#include "Components/ProgressBar.h"
#include "Kismet/GameplayStatics.h"
#include "ElectricityGenerator.h"

void UGameHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Hid generator progress bar when start the game cuz player do not need it, until player working on generator
	HidGeneratorProgressBar();
	GeneratorProgressBar -> SetPercent(ProgressBarPercent);
	
	//This cast has to be change later cuz the GetActorOfClass is return only the first Actor/Character, and the game have more then 1
	//But for now it is okay to use it for test purposes only 
	ElectricityGenerator = Cast<AElectricityGenerator>(UGameplayStatics::GetActorOfClass(GetWorld(), BPGeneratorClass));
}

void UGameHUDWidget::ShowGeneratorProgressBar() const
{
	GeneratorProgressBar->SetVisibility(ESlateVisibility::Visible);
}

void UGameHUDWidget::HidGeneratorProgressBar() const
{
	GeneratorProgressBar->SetVisibility(ESlateVisibility::Hidden);
}

void UGameHUDWidget::SetGeneratorProgressBarPercent(float Value)
{
	GeneratorProgressBar -> SetPercent(ProgressBarPercent);
	ProgressBarPercent = Value;
		
}
