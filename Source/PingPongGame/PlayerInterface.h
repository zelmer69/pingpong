#pragma once

#include "CoreMinimal.h"

#include "UObject/Interface.h"

#include "PlayerInterface.generated.h"


UINTERFACE(MinimalAPI, Blueprintable)

class UPlayerInterface : public UInterface

{

	GENERATED_BODY()

};

class IPlayerInterface

{

	GENERATED_BODY()


public:

	virtual void move(FVector2D Direction) {}

};