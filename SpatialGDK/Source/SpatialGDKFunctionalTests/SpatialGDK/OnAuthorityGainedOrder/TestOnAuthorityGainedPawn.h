// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "TestOnAuthorityGainedPawn.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestOnAuthorityGainedPawn, Log, All);

UCLASS()
class ATestOnAuthorityGainedPawn : public APawn
{
	GENERATED_BODY()
private:
	virtual void OnAuthorityGained() override;

	UPROPERTY(Replicated)
	int32 ExpectedOrder;
	int32 OnAuthorityGainedOrder;

	static int32 StaticOrder;

public:
	ATestOnAuthorityGainedPawn();
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	bool Satisfied() const { return ExpectedOrder == OnAuthorityGainedOrder; }
	void SetExpectedOrder(int32 InOrder);

	static void ResetStaticOrder();
};
