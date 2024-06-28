#include "PongController.h"

void APongController::move(FVector2D Direction)
{
	//recive input from player. Move player pawn in direction of input 
	APawn* PlayerPawn = AController::GetPawn();// get controlled pawn
	
	PlayerPawn->AddActorWorldOffset(PlayerPawn->GetActorRightVector() * Direction.X,true);// move pawn in direction
	RPC_Location(PlayerPawn->GetActorLocation());// replicate movement on server
	
}

void APongController::RPC_Location_Implementation(FVector Newlocation)
{
	AController::GetPawn()->SetActorLocation(Newlocation);// set recived location on controlled pawn 
}

