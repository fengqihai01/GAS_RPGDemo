// CopyRight FQH Demo


#include "Player/RPGPlayerState.h"
#include "GAS/RPGAbilitySystemComponent.h"
#include "GAS/RPGAttributeSet.h"

ARPGPlayerState::ARPGPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<URPGAttributeSet>("AttributeSet");
	NetUpdateFrequency=100;
}

UAbilitySystemComponent* ARPGPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


