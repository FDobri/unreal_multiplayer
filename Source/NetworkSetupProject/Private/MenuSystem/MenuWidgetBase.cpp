// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuSystem/MenuWidgetBase.h"

void UMenuWidgetBase::SetMenuInterface(IMenuInterface* menuInterface)
{
	_menuInterface = menuInterface;
}

void UMenuWidgetBase::Setup()
{
	this->AddToViewport();
	this->bIsFocusable = true;

	UWorld* world = GetWorld();
	if (!ensure(world != nullptr))
		return;

	APlayerController* playerController = world->GetFirstPlayerController();
	if (!ensure(playerController != nullptr))
		return;

	FInputModeUIOnly inputMode;
	inputMode.SetWidgetToFocus(this->TakeWidget());
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	playerController->SetInputMode(inputMode);

	playerController->SetShowMouseCursor(true);
}

void UMenuWidgetBase::Teardown()
{
	this->RemoveFromViewport();
	this->bIsFocusable = false;

	UWorld* world = GetWorld();
	if (!ensure(world != nullptr))
		return;

	APlayerController* playerController = world->GetFirstPlayerController();
	if (!ensure(playerController != nullptr))
		return;

	FInputModeGameOnly inputMode;
	playerController->SetInputMode(inputMode);

	playerController->SetShowMouseCursor(false);
}
