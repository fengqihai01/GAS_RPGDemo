// CopyRight FQH Demo

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGCharacterBase.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public ARPGCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()
public:
	AEnemyCharacter();

	/** Enemy Interface*/
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
	/** End Enemy Interface */
protected:
	virtual void BeginPlay() override;
	
	
};
