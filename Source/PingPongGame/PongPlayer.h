// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerInterface.h"
#include "PongPlayer.generated.h"

UCLASS()

class PINGPONGGAME_API APongPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APongPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	UInputAction* MoveAction;// Input Action for moving left-right

	void Move(const FInputActionValue& Value);// Function for reciving input 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput") // Input context 
		UInputMappingContext* InputMapping;
	IPlayerInterface* ControllerInterface;//Interface from controller
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
