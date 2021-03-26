// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	_globalStartLocation = GetActorLocation();
	_globalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (ActiveTriggers == 0)
	{
		return;
	}

	if (HasAuthority())
	{
		FVector location = GetActorLocation();
		float journeyLength = (_globalTargetLocation - _globalStartLocation).Size();
		float journeyTravelled = (location - _globalStartLocation).Size();
		if (journeyTravelled >= journeyLength)
		{
			Swap(_globalStartLocation, _globalTargetLocation);
		}

		FVector direction = (_globalTargetLocation - _globalStartLocation).GetSafeNormal(0.1f);
		location += direction * MovementSpeed * deltaTime;
		SetActorLocation(location);
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}
