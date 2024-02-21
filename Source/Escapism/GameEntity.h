// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameEntity.generated.h"

class UGameHUDWidget;

UCLASS()
class ESCAPISM_API AGameEntity : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



private:
	//-----Variables-----//
	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	TSubclassOf<UGameHUDWidget> BPGameHudClass;
	
	//-----Pointers-----//
	UPROPERTY(VisibleDefaultsOnly, Category = "Component")
	class UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Component")
	class USpringArmComponent* SpringArmComponent;

protected:
	UPROPERTY(VisibleAnywhere)
	UGameHUDWidget* GameHUDWidget;



	
	//-----Functions-----//
	void MoveForward(const float inputValue);
	void MoveRight(const float inputValue);
public:
	UGameHUDWidget* GetGameHUD();
};
