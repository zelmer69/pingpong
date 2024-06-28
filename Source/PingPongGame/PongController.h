// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerInterface.h"
#include "PongController.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONGGAME_API APongController : public APlayerController, public IPlayerInterface
{
	GENERATED_BODY()
public:
	virtual void move(FVector2D Direction)override;

	 UFUNCTION(Server, Reliable)// replicated function for movement 
	 void RPC_Location(FVector Loc);
};
