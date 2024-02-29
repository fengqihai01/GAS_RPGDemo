// CopyRight FQH Demo


#include "RPGEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Character/RPGCharacter.h"
#include "GAS/RPGAttributeSet.h"


// Sets default values
ARPGEffectActor::ARPGEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh=CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMesh);

	Sphere=CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
	
}

void ARPGEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this,&ARPGEffectActor::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this,&ARPGEffectActor::OnSphereEndOverlap);
	
	
}

void ARPGEffectActor::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		//const UAttributeSet* AttributeSet = AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(URPGAttributeSet::StaticClass());
	
		ARPGCharacter* RPGCharacter = Cast<ARPGCharacter>(OtherActor);
		if (RPGCharacter)
		{
			URPGAttributeSet* AttributeSet=Cast<URPGAttributeSet>(RPGCharacter->GetAttributeSet());
			AttributeSet->SetHealth(AttributeSet->GetHealth()+25.f);
			Destroy();
		}
		
	}
}

void ARPGEffectActor::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}


