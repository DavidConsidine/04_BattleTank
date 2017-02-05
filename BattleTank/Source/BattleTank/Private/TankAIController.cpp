// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		// Move Towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO 

		// Aim towards the player
		auto ControlledTank = Cast<ATank>(GetPawn());
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); // TODO limit fire rate
		
	}
}

