// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "Foodie.h"

#include "Blueprint/UserWidget.h"

#include "PacmanGameMode.generated.h"

/**
 * 
 */

class UUserWidget;


UCLASS()
class PACMAN_API APacmanGameMode : public AGameMode
{
	GENERATED_BODY()

	APacmanGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	void QuickRestart() { RestartGame(); }

	UPROPERTY(BlueprintReadOnly)
	int FoodiesNum;

	inline void IncrFoodiesNum(int Value) { FoodiesNum += Value; }
	
	UFUNCTION(BlueprintCallable)
	void ShowRestartWidget() { Restart_Widget->SetVisibility(ESlateVisibility::Visible); }

	// add widgets
	UPROPERTY(EditAnywhere, Category = "HUD Elements")
	TSubclassOf<UUserWidget> Score_Widget_Class;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
	TSubclassOf<UUserWidget> Restart_Widget_Class;

protected:

	UUserWidget* Score_Widget;
	UUserWidget* Restart_Widget;


};
