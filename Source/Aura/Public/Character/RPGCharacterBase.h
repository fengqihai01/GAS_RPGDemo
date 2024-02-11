// CopyRight FQH Demo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API ARPGCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ARPGCharacterBase();

protected:
	virtual void BeginPlay() override;
	

};