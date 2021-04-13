// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MenuWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSETUPPROJECT_API UMenuWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetMenuInterface(IMenuInterface* menuInterface);
	void Setup();
	void Teardown();

protected:
	IMenuInterface* _menuInterface;
};
