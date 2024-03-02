// CopyRight FQH Demo

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayAbilitySet.h"
#include "GameFramework/HUD.h"
#include "UI/UserWidget/RPGUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "RPGHUD.generated.h"


class URPGWidgetController;
class UOverlayWidgetController;

UCLASS()
class AURA_API ARPGHUD : public AHUD
{
	GENERATED_BODY()
 	
public:
	UPROPERTY()
	TObjectPtr<URPGUserWidget> OverlayUserWidget;

	UFUNCTION()
	UOverlayWidgetController* GetOverlayUserWidgetController (const FWidgetControllerParams& WCParams);
	
	UFUNCTION()
	void InitOverlayWidget(APlayerController* PC,APlayerState* PS,UAbilitySystemComponent* ASC,UAttributeSet* AS);
	
protected:
	virtual void BeginPlay() override;


private:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayUserWidgetControllerClass;

	UPROPERTY()
	UOverlayWidgetController* OverlayWidgetController;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<URPGUserWidget> OverlayUserWidgetClass;
};
