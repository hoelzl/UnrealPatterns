// Copyright Dr. Matthias Hölzl. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class UNREALPATTERNS_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category="Pawn|Input")
	virtual void MoveForward(float Value);

	UFUNCTION(BlueprintCallable, Category="Pawn|Input")
	virtual void MoveRight(float Value);

	UFUNCTION(BlueprintCallable, Category="Pawn|Input")
	virtual void TurnAtRate(float Rate);

	UFUNCTION(BlueprintCallable, Category="Pawn|Input")
	virtual void LookUpAtRate(float Rate);

private:
	FVector GetUnitVectorForAxis(EAxis::Type Axis) const;
	float GetTurnRate() const;
	float GetLookUpRate() const;
};
