// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MenuInterface.h"
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
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& address);

private:
	TSubclassOf<class UUserWidget> _menuClass;
	TSubclassOf<class UUserWidget> _inGameMenuClass;

	class UMenuWidgetBase* _menu;
};
