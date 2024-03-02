// CopyRight FQH Demo


#include "Character/RPGCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/RPGPlayerController.h"
#include "Player/RPGPlayerState.h"
#include "UI/HUD/RPGHUD.h"

ARPGCharacter::ARPGCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator(0,400.f,0);
	GetCharacterMovement()->bConstrainToPlane=true;
	GetCharacterMovement()->bSnapToPlaneAtStart=true;

	bUseControllerRotationPitch=false;
	bUseControllerRotationPitch=false;
	bUseControllerRotationYaw=false;
}

void ARPGCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Sever Init ASC
	InitAbilityActorInfo();
}

void ARPGCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Client Init ASC
	InitAbilityActorInfo();

}

void ARPGCharacter::InitAbilityActorInfo()
{
	ARPGPlayerState* RPGPlayerState = GetPlayerState<ARPGPlayerState>();
	if (RPGPlayerState)
	{
		RPGPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RPGPlayerState,this);
		AbilitySystemComponent = RPGPlayerState->GetAbilitySystemComponent();
		AttributeSet = RPGPlayerState->GetAttributeSet();
		ARPGPlayerController* PlayerController = Cast<ARPGPlayerController>(GetController());
		if (PlayerController)
		{
			ARPGHUD* Arpghud = Cast<ARPGHUD>(PlayerController->GetHUD());
			if (Arpghud)
			{
				Arpghud->InitOverlayWidget(PlayerController,RPGPlayerState,AbilitySystemComponent,AttributeSet);
			}
		}
	}
}
