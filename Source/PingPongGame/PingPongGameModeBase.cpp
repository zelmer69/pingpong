// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPongGameModeBase.h"

FString APingPongGameModeBase::RegisterNewPlayer(APlayerController* NewPlayer)
{
	
	switch (GetNumPlayers())
	{
	default:
		NewPlayer->Destroy();
		return "New Player connected, but already reached max number of players";
		break;
	case (1):
		return "New Player connected, waiting for 1 more player";
		break;
	case(2):
		APingPongGameModeBase::StartGame();
		return "New Player connected, starting the game";
		break;
	}
}
void APingPongGameModeBase::StartGame_Implementation() {

}
