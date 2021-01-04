// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SpatialTestOnAuthorityGainedOrder.h"

#include "Kismet/GameplayStatics.h"
#include "TestOnAuthorityGainedPawn.h"

ASpatialTestOnAuthorityGainedOrder::ASpatialTestOnAuthorityGainedOrder()
	: Super()
	, WaitTime(0.0f)
{
	Author = "Ken.Yu";
	Description = TEXT("Test OnAuthorityGained order for hierarchical actors");
}

void ASpatialTestOnAuthorityGainedOrder::PrepareTest()
{
	Super::PrepareTest();
	ATestOnAuthorityGainedPawn::ResetStaticOrder();
	AddStep(TEXT("Create Pawn"), FWorkerDefinition::Server(1), nullptr, nullptr, [this](float DeltaTime) {
		FVector Position(500.0f, 500.0f, 50.0f);
		ATestOnAuthorityGainedPawn* Pawn =
			GetWorld()->SpawnActor<ATestOnAuthorityGainedPawn>(Position, FRotator::ZeroRotator, FActorSpawnParameters());
		Pawn->SetExpectedOrder(1);
		RegisterAutoDestroyActor(Pawn);

		for (int i = 0; i < 2; i++)
		{
			AddNewChild(Pawn, i + 2);
		}
		FinishStep();
	});

	AddStep(TEXT("Wait"), FWorkerDefinition::AllServers, nullptr, nullptr, [this](float DeltaTime) {
		if (WaitTime > 1.0f)
		{
			WaitTime = 0.0f;
			FinishStep();
		}
		WaitTime += DeltaTime;
	});
}

void ASpatialTestOnAuthorityGainedOrder::AddNewChild(APawn* InPawn, int32 Order)
{
	FVector Position(500.0f, 500.0f, 50.0f);
	ATestOnAuthorityGainedPawn* Pawn =
		GetWorld()->SpawnActor<ATestOnAuthorityGainedPawn>(Position, FRotator::ZeroRotator, FActorSpawnParameters());
	Pawn->SetExpectedOrder(Order);
	RegisterAutoDestroyActor(Pawn);

	Pawn->SetOwner(InPawn);
}
