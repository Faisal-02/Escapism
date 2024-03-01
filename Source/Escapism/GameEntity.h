// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "GameEntity.generated.h"


class UGameHUDWidget;
class UInputMappingContext;
class UInputAction;

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
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

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
	UPROPERTY(VisibleAnywhere, Category = "Run Time")
	UGameHUDWidget* GameHUDWidget;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* PlayerMappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;
	
	//-----Functions-----//
	
	void Move(const FInputActionValue& Value);
	
	void Look(const FInputActionValue& Value);
	
	virtual void InteractWithGenerator(const FInputActionValue& Value);
	virtual void StopInteractWithGenerator(const FInputActionValue& Value);
	
public:
	UGameHUDWidget* GetGameHUD() const;
};
