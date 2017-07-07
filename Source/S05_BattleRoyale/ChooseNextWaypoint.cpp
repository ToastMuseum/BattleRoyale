// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_BattleRoyale.h"
#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	

	//jdeo- get the patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	//jdeo- Protect against no patrol route component
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed;}

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	//jdeo- Protect against empty patrol routes
	if (PatrolPoints.Num() <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("Guard is Missing Patrol Points"));
	}

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	auto IndexName = IndexKey.SelectedKeyName;
	//UE_LOG(LogTemp, Warning, TEXT("Waypoint Name: %s -- Waypoint index: %i"), *(IndexName.ToString()), Index);
	
	//jdeo- set the next waypoint
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	

	//jdeo- Cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;

}
