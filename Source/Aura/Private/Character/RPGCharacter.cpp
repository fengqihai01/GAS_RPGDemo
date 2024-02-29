// CopyRight FQH Demo


#include "Character/RPGCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/RPGPlayerState.h"

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
	}
}
