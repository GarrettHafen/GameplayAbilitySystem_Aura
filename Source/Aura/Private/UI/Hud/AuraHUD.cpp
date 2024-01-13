// Copyright Garrett Hafen


#include "UI/Hud/AuraHUD.h"

#include "UI/Widget/AuraUserWidget.h"

void AAuraHud::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
