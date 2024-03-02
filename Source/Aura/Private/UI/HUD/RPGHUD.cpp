// CopyRight FQH Demo


#include "UI/HUD/RPGHUD.h"

void ARPGHUD::BeginPlay()
{
	Super::BeginPlay();
	
}

UOverlayWidgetController* ARPGHUD::GetOverlayUserWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController==nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this,OverlayUserWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void ARPGHUD::InitOverlayWidget(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayUserWidgetClass,TEXT("OverlayUserWidgetClass is not setting"));
	checkf(OverlayUserWidgetControllerClass,TEXT("OverlayUserWidgetControllerClass is not setting"));

	UUserWidget* UserWidget = CreateWidget(GetWorld(),OverlayUserWidgetClass);
	OverlayUserWidget=Cast<URPGUserWidget>(UserWidget);
	OverlayUserWidget->AddToViewport();
	FWidgetControllerParams WidgetControllerParams(PC,PS,ASC,AS);
	UOverlayWidgetController* OverlayController = GetOverlayUserWidgetController(WidgetControllerParams);
	OverlayUserWidget->SetWidgetController(OverlayController);
}
