// CopyRight FQH Demo


#include "Player/RPGPlayerController.h"

#include "EnhancedInputSubsystems.h"

ARPGPlayerController::ARPGPlayerController()
{
	bReplicates=true;
}

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Log,TEXT("111"));
	check(RPGInputContext);

	UEnhancedInputLocalPlayerSubsystem * EnhanchedSubsystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(EnhanchedSubsystem);

	SetShowMouseCursor(true);
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
