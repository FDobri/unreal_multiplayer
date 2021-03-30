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
	UE_LOG(LogTemp, Warning, TEXT("Hosting server."));
}

void UMainMenu::OnJoinButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Joining server."));
}
