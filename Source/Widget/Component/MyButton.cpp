// ﻿// © 2024 Hoon. A touch of creativity in every line of code.


#include "Widget/Component/MyButton.h"

#include "Styling/SlateTypes.h"

void UMyButton::OnClick()
{
	// OnClickStringParamDelegate 바인딩 된 함수에 StaringParameter1를 전달
	OnClickStringParamDelegate.ExecuteIfBound(StringParameter1);
}

void UMyButton::AddOnClickEvent()
{
	if (!OnClicked.IsBound())
	{
		OnClicked.AddDynamic(this, &UMyButton::OnClick);
	}
}

void UMyButton::SetEnable()
{
	FButtonStyle ButtonStyle = GetStyle();
	ButtonStyle.Normal.TintColor = FSlateColor(ACTIVATE_COL);
	SetStyle(ButtonStyle);
}

void UMyButton::SetDisable()
{
	FButtonStyle ButtonStyle = GetStyle();
	ButtonStyle.Normal.TintColor = FSlateColor(DEACTIVATE_COL);
	SetStyle(ButtonStyle);
}
