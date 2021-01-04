// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "SpatialFunctionalTest.h"
#include "SpatialTestOnAuthorityGainedOrder.generated.h"

UCLASS()
class SPATIALGDKFUNCTIONALTESTS_API ASpatialTestOnAuthorityGainedOrder : public ASpatialFunctionalTest
{
	GENERATED_BODY()
public:
	ASpatialTestOnAuthorityGainedOrder();

	virtual void PrepareTest() override;

private:
	void AddNewChild(APawn* InPawn, int32 Order);

	float WaitTime;
};
