// CopyRight FQH Demo


#include "Player/RPGPlayerController.h"

ARPGPlayerController::ARPGPlayerController()
{
	bReplicates=true;
}

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Log,TEXT("111"));
}
