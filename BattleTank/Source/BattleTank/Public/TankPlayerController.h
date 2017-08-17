// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last include

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(const FVector2D& ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(const FVector& LookDirection, FVector& HitLocation) const;

public:
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000; // 10km in cm
};
