// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDWidget.h"
#include "Components/ProgressBar.h"

void UGameHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Hid generator progress bar cuz player do not need it, until player working on one
	HidGeneratorProgressBar();
	
}

void UGameHUDWidget::ShowGeneratorProgressBar()
{
	GeneratorProgressBar->SetVisibility(ESlateVisibility::Visible);
}

void UGameHUDWidget::HidGeneratorProgressBar()
{
	GeneratorProgressBar->SetVisibility(ESlateVisibility::Hidden);
}
