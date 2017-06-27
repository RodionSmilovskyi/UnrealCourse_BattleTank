// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIPlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIPlayerController possesing a tank: %s"), *(ControlledTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("TankAIPlayerController Begin Play"));

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find a player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}