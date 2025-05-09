// ﻿// © 2024 Hoon. A touch of creativity in every line of code.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyTabButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class AUTOWIDGETSWITCHER_API UMyTabButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> TabButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> TabText;

public:
	void SetTabText(FString TabName);

	UMyButton* GetButton();

	void ActivateButton();
	void DeactivateButton();

};
