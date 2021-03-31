// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "PlatformTrigger.h"
#include "MainMenu.h"
#include "InGameMenu.h"
#include "MenuWidgetBase.h"

UMultiplayerGameInstance::UMultiplayerGameInstance(const FObjectInitializer& objectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> menuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (!ensure(menuBPClass.Class != nullptr))
		return;
	_menuClass = menuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> inGameMenuBPClass(TEXT("/Game/MenuSystem/WBP_InGameMenu"));
	if (!ensure(inGameMenuBPClass.Class != nullptr))
		return;
	_inGameMenuClass = inGameMenuBPClass.Class;
}

void UMultiplayerGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *_menuClass->GetName());
}

void UMultiplayerGameInstance::LoadMenu()
{
	if (!ensure(_menuClass != nullptr))
		return;
	_menu = CreateWidget<UMainMenu>(this, _menuClass);
	if (!ensure(_menu != nullptr))
		return;
	_menu->Setup();
	_menu->SetMenuInterface(this);
}

void UMultiplayerGameInstance::LoadInGameMenu()
{
	if (!ensure(_inGameMenuClass != nullptr))
		return;
	UMenuWidgetBase* inGameMenu = CreateWidget<UInGameMenu>(this, _inGameMenuClass);
	if (!ensure(inGameMenu != nullptr))
		return;
	inGameMenu->Setup();
	inGameMenu->SetMenuInterface(this);
}

void UMultiplayerGameInstance::Host()
{
	if (_menu != nullptr)
	{
		_menu->Teardown();
	}
	UEngine* engine = GetEngine();
	if (!ensure(engine != nullptr))
		return;
	engine->AddOnScreenDebugMessage(0, 2, FColor::Yellow, TEXT("Hosting"));

	UWorld* world = GetWorld();
	if (!ensure(world != nullptr))
		return;
	world->ServerTravel("/Game/ThirdPersonBP/Maps/ThirdPersonExampleMap?listen");
}

void UMultiplayerGameInstance::Join(const FString& address)
{
	if (_menu != nullptr)
	{
		_menu->Teardown();
	}
	UEngine* engine = GetEngine();
	if (!ensure(engine != nullptr))
		return;
	engine->AddOnScreenDebugMessage(0, 5, FColor::Yellow, FString::Printf(TEXT("Joining %s"), *address));

	APlayerController* playerController = GetFirstLocalPlayerController();
	if (!ensure(playerController != nullptr))
		return;
	playerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);
}
