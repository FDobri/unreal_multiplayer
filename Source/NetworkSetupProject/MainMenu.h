// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSETUPPROJECT_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

public:
	UFUNCTION()
	void OnHostButtonClicked();

	UFUNCTION()
	void OnJoinButtonClicked();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* JoinButton;
};