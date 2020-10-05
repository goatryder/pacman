// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"

// Sets default values
AEnemyPawn::AEnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AEnemyPawn::Hunt()
{

	State = EEnemyState::Default;

	StateChangedEvent.Broadcast(State);

}

void AEnemyPawn::Idle()
{

	State = EEnemyState::Idle;

	StateChangedEvent.Broadcast(State);

}
