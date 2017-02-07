// Copyright David Considine.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // put new includes above


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
};
