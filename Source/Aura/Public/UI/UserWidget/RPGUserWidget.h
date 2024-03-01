// CopyRight FQH Demo

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RPGUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API URPGUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:

	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetControllerSet();
};
