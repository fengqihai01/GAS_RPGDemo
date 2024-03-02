// CopyRight FQH Demo

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "Interaction/EnemyInterface.h"
#include "RPGPlayerController.generated.h"

class UInputMappingContext;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class AURA_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ARPGPlayerController();
	void PlayerTick(float DeltaTime) override;
protected:
	virtual  void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext>  RPGInputContext;

	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UFUNCTION()
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	IEnemyInterface* ThisActor;
	IEnemyInterface* LastActor;



	//TObjectPtr<IEnemyInterface> LastActor;
	//TObjectPtr<IEnemyInterface> ThisActor;
};
