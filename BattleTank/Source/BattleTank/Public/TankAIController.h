// Copyright David Considine.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:
	// how close can the AI tank get
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 3000.0f;
};
