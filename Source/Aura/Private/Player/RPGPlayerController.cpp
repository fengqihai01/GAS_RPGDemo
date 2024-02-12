// CopyRight FQH Demo


#include "Player/RPGPlayerController.h"

#include "EnhancedInputComponent.h"
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
	EnhanchedSubsystem->AddMappingContext(RPGInputContext,0);
	
	SetShowMouseCursor(true);
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ARPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent=CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ARPGPlayerController::Move);
}

void ARPGPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector= InputActionValue.Get<FVector2D>();
	const FRotator ControlYawRotator=FRotator(0,GetControlRotation().Yaw,0);
	const FVector ForwardVector=FRotationMatrix(ControlYawRotator).GetUnitAxis(EAxis::X);
	const FVector RightVector=FRotationMatrix(ControlYawRotator).GetUnitAxis(EAxis::Y);
	if (APawn* ControlPawn=GetPawn())
	{
		ControlPawn->AddMovementInput(ForwardVector,InputAxisVector.Y);
		ControlPawn->AddMovementInput(RightVector,InputAxisVector.X);
	}
}
