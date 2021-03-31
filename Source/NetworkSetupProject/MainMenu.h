// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "MenuInterface.h"
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
	UFUNCTION()
	void OnCancelButtonClicked();

	void SetMenuInterface(IMenuInterface* menuInterface);
	void Setup();
	void Teardown();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* CancelButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UWidget* InitialMenu;

private:
	IMenuInterface* _menuInterface;
};
