// Fill out your copyright notice in the Description page of Project Settings.


#include "Foodie.h"

#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

#include "PacmanGameMode.h"

// Sets default values
AFoodie::AFoodie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFoodie::BeginPlay()
{
	Super::BeginPlay();

	PacmanGM = Cast<APacmanGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (PacmanGM != nullptr) {

		PacmanGM->IncrFoodiesNum(1);

	}

}

// Called every frame
void AFoodie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodie::Consume()
{

	UGameplayStatics::PlaySound2D(this, ConsumtionSound);

	FoodieEatenEvent.Broadcast(FoodieType);

	Destroy();

	if (PacmanGM != nullptr) {

		PacmanGM->IncrFoodiesNum(-1);

	}

}
