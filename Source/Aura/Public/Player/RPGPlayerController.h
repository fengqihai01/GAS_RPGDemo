// CopyRight FQH Demo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class AURA_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ARPGPlayerController();
protected:
	virtual  void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext>  RPGInputContext;
};
