// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Math/UnrealMathUtility.h"
#include <Kismet/KismetMathLibrary.h>
// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABall::ServerUpdateVelocity_Implementation(FHitResult HitResult,UStaticMeshComponent* BallRef) {

	if (BallRef && BallRef->IsSimulatingPhysics())// make sure ball exists and has physics on 
	{
		FVector velocity = FMath::GetReflectionVector(this->GetActorForwardVector(), HitResult.Normal) * 800;//calculate velocity 
		BallRef->SetPhysicsLinearVelocity(velocity);// set velocity 
		FRotator rotation = UKismetMathLibrary::MakeRotationFromAxes(velocity, this->GetActorRightVector(), this->GetActorUpVector());//figure out rotation 
		int dRotator = FMath::RandRange(-10, 10);// get random number in range (-10, 10) 
		rotation = FRotator(rotation.Roll, rotation.Pitch, rotation.Yaw - dRotator);// get rotation substract random number from Yaw axis to make ball feel more random 
		BallRef->SetWorldRotation(rotation);// set rotation 
		
	}
	
}

