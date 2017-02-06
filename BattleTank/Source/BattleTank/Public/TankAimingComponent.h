// Copyright David Considine.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//reloading, aiming, locked
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};
// Forward Declaration
class UTankTurret;
class UTankBarrel; 

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Reloading;

private:
	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

	// Sets default values for this component's properties
	UTankAimingComponent();

	void MoveBarrelTowards(FVector AimDirection);
};
