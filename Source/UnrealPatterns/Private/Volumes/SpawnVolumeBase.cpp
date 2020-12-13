// Copyright Dr. Matthias Hölzl. All Rights Reserved.


#include "Volumes/SpawnVolumeBase.h"

ASpawnVolumeBase::ASpawnVolumeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpawnVolumeBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolumeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

