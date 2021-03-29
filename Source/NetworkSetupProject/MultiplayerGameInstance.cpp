// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "PlatformTrigger.h"

UMultiplayerGameInstance::UMultiplayerGameInstance(const FObjectInitializer& objectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor game instance log."));

	static ConstructorHelpers::FClassFinder<UUserWidget> menuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (!ensure(menuBPClass.Class != nullptr))
		return;
	_menuClass = menuBPClass.Class;
}

void UMultiplayerGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *_menuClass->GetName());
}

void UMultiplayerGameInstance::LoadMenu()
{
	if (!ensure(_menuClass != nullptr))
		return;
	UUserWidget* menu = CreateWidget<UUserWidget>(this, _menuClass);
	if (!ensure(menu != nullptr))
		return;
	menu->AddToViewport();
	menu->bIsFocusable = true;
}

void UMultiplayerGameInstance::Host()
{
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
	UEngine* engine = GetEngine();
	if (!ensure(engine != nullptr))
		return;
	engine->AddOnScreenDebugMessage(0, 5, FColor::Yellow, FString::Printf(TEXT("Joining %s"), *address));

	APlayerController* playerController = GetFirstLocalPlayerController();
	if (!ensure(playerController != nullptr))
		return;
	playerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);
}
