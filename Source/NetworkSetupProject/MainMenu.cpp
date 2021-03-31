// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

bool UMainMenu::Initialize()
{
	bool initialized = Super::Initialize();
	if (!initialized)
	{
		return false;
	}
	
	if (!ensure(HostButton != nullptr && JoinButton != nullptr))
	{
		return false;
	}

	HostButton->OnClicked.AddDynamic(this, &UMainMenu::OnHostButtonClicked);
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OnJoinButtonClicked);
	CancelButton->OnClicked.AddDynamic(this, &UMainMenu::OnCancelButtonClicked);
	JoinIPAddressButton->OnClicked.AddDynamic(this, &UMainMenu::OnJoinIPAdressButtonClicked);
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
	if (!ensure(MenuSwitcher != nullptr && JoinMenu != nullptr))
		return;

	MenuSwitcher->SetActiveWidget(JoinMenu);
	UE_LOG(LogTemp, Warning, TEXT("Joining server."));
}

void UMainMenu::OnCancelButtonClicked()
{
	if (!ensure(MenuSwitcher != nullptr && InitialMenu != nullptr))
		return;

	MenuSwitcher->SetActiveWidget(InitialMenu);
}

void UMainMenu::OnJoinIPAdressButtonClicked()
{
	if (_menuInterface != nullptr)
	{
		const FString ipAddress = IPAddressInputField->GetText().ToString();
		_menuInterface->Join(ipAddress);
		UE_LOG(LogTemp, Warning, TEXT("Joining server."));
	}
}
