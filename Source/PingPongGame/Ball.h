
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Ball.generated.h"

UCLASS()
class PINGPONGGAME_API ABall : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	ABall();

public:

	UFUNCTION(BlueprintAuthorityOnly, Server, Reliable, BlueprintCallable)// replicated function for ball's movement 
		void ServerUpdateVelocity(FHitResult HitResult, UStaticMeshComponent* BallRef);


};
