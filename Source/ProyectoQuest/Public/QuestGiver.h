// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestInteractable.h"
#include "QuestDefinition.h"
#include "QuestGiver.generated.h"

UCLASS()
class PROYECTOQUEST_API AQuestGiver : public AActor, public IQuestInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AQuestGiver();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	TObjectPtr<UQuestDefinition> QuestDefinition;
	
	virtual void Interact_Implementation(AActor* Interactor) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
