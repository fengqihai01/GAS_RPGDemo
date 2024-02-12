// CopyRight FQH Demo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interaction/EnemyInterface.h"
#include "RPGCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API ARPGCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ARPGCharacterBase();

protected:
	virtual void BeginPlay() override;

	
	UPROPERTY(EditAnywhere,Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon ;


};
