// ﻿// © 2024 Hoon. A touch of creativity in every line of code.


#include "Widget/MyTabButtonWidget.h"
#include "Widget/Component/MyButton.h"

#include "Components/TextBlock.h"

void UMyTabButtonWidget::SetTabText(FString TabName)
{
	TabText->SetText(FText::FromString(TabName));
}

UMyButton* UMyTabButtonWidget::GetButton()
{
	return TabButton;
}

void UMyTabButtonWidget::ActivateButton()
{
	TabButton->SetEnable();
}

void UMyTabButtonWidget::DeactivateButton()
{
	TabButton->SetDisable();
}
