// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidgetBase.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSETUPPROJECT_API UMainMenu : public UMenuWidgetBase
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
	void OnQuitButtonClicked();
	UFUNCTION()
	void OnCancelButtonClicked();
	UFUNCTION()
	void OnJoinIPAdressButtonClicked();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* QuitButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* CancelButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* JoinIPAddressButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UEditableTextBox* IPAddressInputField;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UWidget* InitialMenu;
};
