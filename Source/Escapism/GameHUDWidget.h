// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPISM_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;



	//-----Variables-----//
	
	//-----Pointers-----//
	UPROPERTY(EditDefaultsOnly, Category = "Generator HUD",  meta = (BindWidget))
	class UProgressBar* GeneratorProgressBar;
	
	//-----Functions-----//
public:
	void ShowGeneratorProgressBar();
	void HidGeneratorProgressBar();
};
