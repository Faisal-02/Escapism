// Fill out your copyright notice in the Description page of Project Settings.


#include "GameEntity.h"
#include "GameHUDWidget.h"

#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"

// Sets default values
AGameEntity::AGameEntity()
{
 	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprinArm"));
	SpringArmComponent -> bUsePawnControlRotation = true;
	SpringArmComponent -> SetupAttachment(RootComponent);
	
	CameraComponent -> SetupAttachment(SpringArmComponent);
	
}

// Called when the game starts or when spawned
void AGameEntity::BeginPlay()
{
	Super::BeginPlay();

	//This will show the mouse cursor all the time, only for testing purposes
	UGameplayStatics::GetPlayerController(GetWorld(), 0) -> bShowMouseCursor = true;

	
	GameHUDWidget = Cast<UGameHUDWidget>(CreateWidget(GetWorld(), BPGameHudClass));
	GameHUDWidget->AddToViewport();
}

void AGameEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent -> BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGameEntity::Move);

		EnhancedInputComponent -> BindAction(LookAction, ETriggerEvent::Triggered, this, &AGameEntity::Look);
	}
	
}

UGameHUDWidget* AGameEntity::GetGameHUD()
{
	return  GameHUDWidget;
}

void AGameEntity::Move(const FInputActionValue& Value)
{
	//This will get the value of the InputAction 
	const FVector2D MoveValue = Value.Get<FVector2D>();

	
	//This will add the Forward movement to Controller
	AddMovementInput(GetActorForwardVector(), MoveValue.X);

	//This will add the Right movement to Controller
	AddMovementInput(GetActorRightVector(), MoveValue.Y);
}

void AGameEntity::Look(const FInputActionValue& Value)
{
	//This will get the value of the InputAction 
	const FVector2D LookValue = Value.Get<FVector2D>();

	//This will add the Yaw movement to Controller
	AddControllerYawInput(LookValue.X);

	//This will add the Pitch movement to Controller
	AddControllerPitchInput(LookValue.Y);

	
}

void AGameEntity::PlayerInteraction(const FInputActionValue& Value)
{
	//Do nothing, I will override this in children cuz its will have different actions
	//Overall this function will handle the interaction with world environment (Game World) With E Button.

	
}




