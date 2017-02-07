// Copyright David Considine.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // put new includes above

//Forward Declarations
class UTankTurret;
class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category= "Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0f; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.0f;
	
	double LastFireTime;

	UTankBarrel* Barrel = nullptr; // TODO remove
};
