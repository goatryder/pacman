// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanGameMode.h"

#include "Foodie.h"


APacmanGameMode::APacmanGameMode() {

	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APacmanGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (Score_Widget_Class) {

		Score_Widget = CreateWidget<UUserWidget>(GetWorld(), Score_Widget_Class);
		Score_Widget->AddToViewport();

	} // score widget

	if (Restart_Widget_Class) {

		Restart_Widget = CreateWidget<UUserWidget>(GetWorld(), Restart_Widget_Class);
		Restart_Widget->AddToViewport();

		Restart_Widget->SetVisibility(ESlateVisibility::Hidden);

	} // restart widget

}
