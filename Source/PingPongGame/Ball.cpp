
#include "Ball.h"
#include "Math/UnrealMathUtility.h"
#include <Kismet/KismetMathLibrary.h>
// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}


void ABall::ServerUpdateVelocity_Implementation(FHitResult HitResult, UStaticMeshComponent* BallRef) {

	if (BallRef && BallRef->IsSimulatingPhysics())// make sure ball exists and has physics on 
	{

		FVector velocity = FMath::GetReflectionVector(this->GetActorForwardVector(), HitResult.Normal) * 800;//calculate velocity 
		BallRef->SetPhysicsLinearVelocity(velocity);// set velocity 
		FRotator rotation = UKismetMathLibrary::MakeRotationFromAxes(velocity, this->GetActorRightVector(), this->GetActorUpVector());//figure out rotation 


		BallRef->SetWorldRotation(rotation);// set rotation 
			
	}

}

