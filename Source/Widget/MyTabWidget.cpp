// ﻿// © 2024 Hoon. A touch of creativity in every line of code.


#include "Widget/MyTabWidget.h"
#include "Widget/MyTabButtonWidget.h"
#include "Widget/Component/MyButton.h"

#include "Components/WidgetSwitcher.h"
#include "Components/HorizontalBox.h"


UMyTabWidget::UMyTabWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	const ConstructorHelpers::FClassFinder<UMyTabButtonWidget> TabButtonClassRef(TEXT("/Game/UI/WBP_TabButton.WBP_TabButton_C"));
	if (TabButtonClassRef.Class)
	{
		TabButtonClass = TabButtonClassRef.Class;
	}
}

void UMyTabWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	for (int32 i = 0; i < ViewerContainer->GetNumWidgets(); i++)
	{
		UUserWidget* Viewer = Cast<UUserWidget>(ViewerContainer->GetWidgetAtIndex(i));

		if (Viewer)
		{
			UMyTabButtonWidget* NewTab = CreateWidget<UMyTabButtonWidget>(this, TabButtonClass);
			NewTab->SetTabText(Viewer->GetName());
			NewTab->DeactivateButton();

			UMyButton* NewButton = NewTab->GetButton();
			NewButton->SetStringParameter1(Viewer->GetName());
			NewButton->OnClickStringParamDelegate.BindUObject(this, &UMyTabWidget::SwitchWidget);
			NewButton->AddOnClickEvent();

			if (i == 0) { NewTab->ActivateButton(); }

			TabContainer->AddChildToHorizontalBox(NewTab);
		}
	}
}

void UMyTabWidget::SwitchWidget(FString& ChangeWidgetName)
{
	for (int32 i = 0; i < ViewerContainer->GetChildrenCount(); i++)
	{
		UUserWidget* Viewer = Cast<UUserWidget>(ViewerContainer->GetChildAt(i));
		UMyTabButtonWidget* Tab = Cast<UMyTabButtonWidget>(TabContainer->GetChildAt(i));

		if (Viewer->GetName() == ChangeWidgetName)
		{
			ViewerContainer->SetActiveWidgetIndex(i);
			Tab->ActivateButton();
		}
		else
		{
			Tab->DeactivateButton();
		}
	}

}
