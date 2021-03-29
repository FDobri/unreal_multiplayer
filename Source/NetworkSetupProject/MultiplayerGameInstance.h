// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MultiplayerGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSETUPPROJECT_API UMultiplayerGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:	
	UMultiplayerGameInstance(const FObjectInitializer& objectInitializer);

protected:
	virtual void Init() override;

public:
	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& address);

private:
	TSubclassOf<class UUserWidget> _menuClass;
};
