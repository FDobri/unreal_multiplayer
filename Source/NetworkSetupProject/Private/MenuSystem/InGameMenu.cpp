// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuSystem/InGameMenu.h"

bool UInGameMenu::Initialize()
{
	bool initialized = Super::Initialize();
	if (!initialized)
	{
		return false;
	}

	if (!ensure(CancelButton != nullptr && LeaveButton != nullptr))
	{
		return false;
	}

	CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::OnCancelButtonClicked);
	LeaveButton->OnClicked.AddDynamic(this, &UInGameMenu::OnLeaveButtonClicked);

	return true;
}

void UInGameMenu::OnCancelButtonClicked()
{
	Teardown();
}

void UInGameMenu::OnLeaveButtonClicked()
{
	if (_menuInterface != nullptr)
	{
		Teardown();
		_menuInterface->LoadMainMenu();
	}
}
