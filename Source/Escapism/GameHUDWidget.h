// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUDWidget.generated.h"

class AElectricityGenerator;
/**
 * 
 */
UCLASS()
class ESCAPISM_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	//-----Variables-----//
	
	float ProgressBarPercent = 0.f;
	
	//-----Pointers-----//
	
	UPROPERTY(EditDefaultsOnly, Category = "Generator HUD",  meta = (BindWidget))
	class UProgressBar* GeneratorProgressBar;

	UPROPERTY(VisibleAnywhere, Category = "Run Time")
	AElectricityGenerator* ElectricityGenerator;

	
	//-----Template-----//
	
	UPROPERTY(EditDefaultsOnly, Category = "Generator")
	TSubclassOf<AElectricityGenerator> BPGeneratorClass;

	
	//-----Functions-----//
public:
	void ShowGeneratorProgressBar() const;
	void HidGeneratorProgressBar() const;
	void SetGeneratorProgressBarPercent(float Value);
};
