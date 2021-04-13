// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MenuSystem/MenuInterface.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MultiplayerGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSETUPPROJECT_API UMultiplayerGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:	
	UMultiplayerGameInstance(const FObjectInitializer& objectInitializer);

protected:
	virtual void Init() override;

public:
	UFUNCTION(BlueprintCallable)
	void LoadMenu();
	
	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

	UFUNCTION(Exec)
	void Host() override;

	UFUNCTION(Exec)
	void Join(const FString& address) override;

	UFUNCTION(Exec)
	void LoadMainMenu() override;

private:
	void OnServerSessionEnded(UWorld* world, UNetDriver* netDriver, ENetworkFailure::Type failureType, const FString& errorString);

private:
	TSubclassOf<class UUserWidget> _menuClass;
	TSubclassOf<class UUserWidget> _inGameMenuClass;

	class UMenuWidgetBase* _menu;
	class UMenuWidgetBase* _inGameMenu;

	const FString PLAYABLE_MAP_PATH = "/Game/ThirdPersonBP/Maps/ThirdPersonExampleMap?listen";
	const FString MAIN_MENU_MAP_PATH = "/Game/MenuSystem/MainMenu";
};
