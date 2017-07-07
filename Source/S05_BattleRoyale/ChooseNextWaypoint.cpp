// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_BattleRoyale.h"
#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrollingGuard.h" //TODO: Remove Coupling
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	// TODO: Protect against empty patrol routes

	//jdeo- get the patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;


	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	auto IndexName = IndexKey.SelectedKeyName;
	UE_LOG(LogTemp, Warning, TEXT("Waypoint Name: %s -- Waypoint index: %i"), *(IndexName.ToString()), Index);
	
	//jdeo- set the next waypoint
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	

	//jdeo- Cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;

}
