// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "CrossServerPossessionTest.h"

#include "Containers/Array.h"
#include "EngineClasses/SpatialNetDriver.h"
#include "GameFramework/Controller.h"
#include "SpatialFunctionalTestFlowController.h"
#include "SpatialGDKFunctionalTests/SpatialGDK/TestActors/TestMovementCharacter.h"
#include "TestPossessionPawn.h"
#include "TestPossessionController.h"

/**
 * This test tests 1 Controller remote possess over 1 Pawn.
 *
 * This test expects a load balancing grid and ACrossServerPossessionGameMode
 * Recommand to use 2*2 load balancing grid because the position is written in the code
 * The client workers begin with a player controller and their default pawns, which they initially possess.
 * The flow is as follows:
 *	Recommend to use PossessionGym.umap in UnrealGDKTestGyms project which ready for tests.
 *  - Setup:
 *    - Specify `Multi Worker Settings Class` as Zoning 2x2(e.g. BP_Possession_Settings_Zoning2_2 of UnrealGDKTestGyms)
 *	  - Set `Num Required Clients` as 1
 *  - Test:
 *	  - Create a Pawn in first quadrant
 *	  - Create Controller in other quadrant
 *	  - Wait for Pawn in right worker.
 *	  -	The Controller possess the Pawn in server-side
 *	- Result Check:
 *    - ATestPossessionController::OnPossess should be called 1 time
 *	  - Controller should migration
 */

ACrossServerPossessionTest::ACrossServerPossessionTest()
{
	Author = "Ken.Yu";
	Description = TEXT("Test Cross-Server Possession");
}

void ACrossServerPossessionTest::PrepareTest()
{
	Super::PrepareTest();

	AddStep(TEXT("Cross-Server Possession"), FWorkerDefinition::AllServers, nullptr, nullptr, [this](float) {
		ATestPossessionPawn* Pawn = GetPawn();
		AssertIsValid(Pawn, TEXT("Test requires a Pawn"));
		if (ASpatialFunctionalTestFlowController* FlowController = GetLocalFlowController())
		{
			ATestPossessionController* Controller = GetController();
			if (Controller && Controller->HasAuthority())
			{
				AssertTrue(Controller->HasAuthority(), TEXT("Controller should HasAuthority"), Controller);
				AssertFalse(Pawn->HasAuthority(), TEXT("Pawn shouldn't HasAuthority"), Pawn);
				Controller->RemotePossessOnServer(Pawn);
			}
		}
		FinishStep();
	});

	AddStep(
		TEXT("Check test result"), FWorkerDefinition::Server(1),
		[this]() -> bool {
			LogStep(ELogVerbosity::Log, FString::Printf(TEXT("OnPossessCalled:%d"), ATestPossessionController::OnPossessCalled));
			return ATestPossessionController::OnPossessCalled >= 1;
		},
		nullptr,
		[this](float) {
			if (ASpatialFunctionalTestFlowController* FlowController = GetLocalFlowController())
			{
				ATestPossessionController* Controller = GetController();
				if (Controller && Controller->HasAuthority())
				{
					AssertTrue(Controller->IsMigration(), TEXT("Controller should migration"), Controller);

					Controller->UnPossess();
				}
			}
			FinishStep();
		});

	AddCleanStep();
}

void ACrossServerPossessionTest::CreateControllerAndPawn()
{
	CreateController(FVector(-500.0f, -500.0f, 50.0f));
	CreatePawn(FVector(500.0f, 500.0f, 50.0f));
}
