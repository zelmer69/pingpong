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



void APongPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)// basic input setup
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());//1: get player controller
	ControllerInterface = Cast<IPlayerInterface>(PlayerController);// check if controller implements interface for movement
	//2: add new input mapping context 
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
	//3: bind input action for movement 
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APongPlayer::Move);


}

void APongPlayer::Move(const FInputActionValue& Value)
{
	if (ControllerInterface) {
		FVector2D Axis2DValue = Value.Get<FVector2D>(); // Get input in Vector2D
		ControllerInterface->move(Axis2DValue);// call controller interface

	}
}
