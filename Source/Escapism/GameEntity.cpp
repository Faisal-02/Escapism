// Fill out your copyright notice in the Description page of Project Settings.


#include "GameEntity.h"
#include "GameHUDWidget.h"

#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

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

// Called every frame
void AGameEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent -> BindAxis("Forward", this, &AGameEntity::MoveForward);
	PlayerInputComponent -> BindAxis("Right", this, &AGameEntity::MoveRight);

	PlayerInputComponent -> BindAxis("Turn", this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent -> BindAxis("Lockup", this, &ACharacter::AddControllerPitchInput);
	
}

void AGameEntity::MoveForward(const float inputValue)
{
	AddMovementInput(GetActorForwardVector() * inputValue);
}

void AGameEntity::MoveRight(const float inputValue)
{
	AddMovementInput(GetActorRightVector() * inputValue);
}

void AGameEntity::PlayerInteraction()
{
	//Do nothing, I will override this in children cuz its will have different actions
	//Overall this function will handle the interaction with world environment (Game World) With E Button.

	UE_LOG(LogTemp, Warning, TEXT("i am GameEntity class"));
}

UGameHUDWidget* AGameEntity::GetGameHUD()
{
	return GameHUDWidget;
}
