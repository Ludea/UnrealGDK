// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestOnAuthorityGainedPawn.h"
#include "Net/UnrealNetwork.h"
#include "SpatialTestOnAuthorityGainedOrder.h"

int32 ATestOnAuthorityGainedPawn::StaticOrder = 0;

DEFINE_LOG_CATEGORY(LogTestOnAuthorityGainedPawn);

ATestOnAuthorityGainedPawn::ATestOnAuthorityGainedPawn()
{
	ExpectedOrder = 0;
	OnAuthorityGainedOrder = 0;
}

void ATestOnAuthorityGainedPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATestOnAuthorityGainedPawn, ExpectedOrder);
}

void ATestOnAuthorityGainedPawn::OnAuthorityGained()
{
	Super::OnAuthorityGained();
	OnAuthorityGainedOrder = ++StaticOrder;
	UE_LOG(LogTestOnAuthorityGainedPawn, Log, TEXT("%s OnAuthorityGained: ExpectedOrder:%d OnAuthorityGainedOrder:%d"), *GetName(),
		   ExpectedOrder, OnAuthorityGainedOrder);
}

void ATestOnAuthorityGainedPawn::SetExpectedOrder(int32 InOrder)
{
	ExpectedOrder = InOrder;
	UE_LOG(LogTestOnAuthorityGainedPawn, Log, TEXT("%s SetExpectedOrder: ExpectedOrder:%d"), *GetName(), ExpectedOrder);
}

void ATestOnAuthorityGainedPawn::ResetStaticOrder()
{
	StaticOrder = 0;
	UE_LOG(LogTestOnAuthorityGainedPawn, Log, TEXT("ResetStaticOrder"));
}
