// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PingPongGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONGGAME_API APingPongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FString RegisterNewPlayer(APlayerController* NewPlayer);
	UFUNCTION(BlueprintNativeEvent)
	void StartGame();
	
};
