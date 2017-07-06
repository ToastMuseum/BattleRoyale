// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_BattleRoyale.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	auto IndexName = IndexKey.SelectedKeyName;
	UE_LOG(LogTemp, Warning, TEXT("Waypoint Name: %s -- Waypoint index: %i"), *(IndexName.ToString()), Index);
	
	return EBTNodeResult::Succeeded;

}
