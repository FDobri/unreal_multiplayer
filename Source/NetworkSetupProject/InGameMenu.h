// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidgetBase.h"
#include "Components/Button.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSETUPPROJECT_API UInGameMenu : public UMenuWidgetBase
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize();

protected:
	UFUNCTION()
	void OnCancelButtonClicked();

	UFUNCTION()
	void OnLeaveButtonClicked();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* CancelButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* LeaveButton;
};
