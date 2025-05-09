// ﻿// © 2024 Hoon. A touch of creativity in every line of code.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyTabWidget.generated.h"

/**
 * 
 */
UCLASS()
class AUTOWIDGETSWITCHER_API UMyTabWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UMyTabWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativePreConstruct() override;

	void SwitchWidget(FString& ChangeWidgetName);

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> TabContainer;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UWidgetSwitcher> ViewerContainer;

	UPROPERTY()
	TSubclassOf<class UMyTabButtonWidget> TabButtonClass;

};
