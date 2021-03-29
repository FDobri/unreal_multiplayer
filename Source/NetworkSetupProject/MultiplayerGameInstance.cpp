// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerGameInstance.h"
#include "Engine/Engine.h"

UMultiplayerGameInstance::UMultiplayerGameInstance(const FObjectInitializer& objectInitializer)
{
	//Super(objectInitializer);
	UE_LOG(LogTemp, Warning, TEXT("Constructor game instance log."));
}

void UMultiplayerGameInstance::Init()
{
	//Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("Constructor init log."));
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
