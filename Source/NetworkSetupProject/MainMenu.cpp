// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

bool UMainMenu::Initialize()
{
	bool initialized = Super::Initialize();
	if (!initialized)
	{
		return false;
	}
	
	if (!ensure(HostButton != nullptr) || !ensure(JoinButton != nullptr))
	{
		return false;
	}

	HostButton->OnClicked.AddDynamic(this, &UMainMenu::OnHostButtonClicked);
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OnJoinButtonClicked);
	return true;
}

void UMainMenu::OnHostButtonClicked()
{
	if (_menuInterface != nullptr)
	{
		_menuInterface->Host();
		UE_LOG(LogTemp, Warning, TEXT("Hosting server."));
	}
}

void UMainMenu::OnJoinButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Joining server."));
}

void UMainMenu::SetMenuInterface(IMenuInterface* menuInterface)
{
	_menuInterface = menuInterface;
}

void UMainMenu::Setup()
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

void UMainMenu::Teardown()
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
