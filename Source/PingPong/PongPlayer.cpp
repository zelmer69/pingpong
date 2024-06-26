// Fill out your copyright notice in the Description page of Project Settings.


#include "PongPlayer.h"
#include "EnhancedInputSubsystems.h"
#include <EnhancedInputComponent.h>



// Sets default values
APongPlayer::APongPlayer()
{
 	// No need for tick here

	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APongPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void APongPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	ControllerInterface = Cast<IPlayerInterface>(PlayerController);// check if controller implements interface

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APongPlayer::Move);
	

}

void APongPlayer::Move(const FInputActionValue& Value)
{

	FVector2D Axis2DValue = Value.Get<FVector2D>(); // Get input in Vector2D
	
	
	ControllerInterface->move(Axis2DValue);
}
