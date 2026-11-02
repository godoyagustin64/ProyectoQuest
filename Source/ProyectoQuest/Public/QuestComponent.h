// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FQuestRuntime.h"
#include "QuestGameState.h"
#include "QuestComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnQuestStarted,
	FQuestRuntime,
	QuestData
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnQuestProgressChanged,
	FQuestRuntime,
	QuestData
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnQuestCompleted,
	FQuestRuntime,
	QuestData
);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROYECTOQUEST_API UQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UQuestComponent();
	
	UPROPERTY(BlueprintReadOnly, Category = "Quest")
	TArray<FQuestRuntime> ActiveQuests;
	
	UFUNCTION(BlueprintCallable, Category = "Quest")
	bool FindQuestByID(
		FName QuestID,
		FQuestRuntime& QuestData,
		int32& QuestIndex
	);
	
	UFUNCTION(BlueprintCallable, Category = "Quest")
	bool AddQuest(UQuestDefinition* QuestDefinition);
	
	UPROPERTY(BlueprintAssignable, Category = "Quest|Events")
	FOnQuestStarted OnQuestStarted;

	UPROPERTY(BlueprintAssignable, Category = "Quest|Events")
	FOnQuestProgressChanged OnQuestProgressChanged;

	UPROPERTY(BlueprintAssignable, Category = "Quest|Events")
	FOnQuestCompleted OnQuestCompleted;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleGameplayObjective(
		EQuestObjectiveType ObjectiveType,
		FName TargetID,
		int32 Amount
	);
	
	void UpdateObjectiveProgress(
	int32 QuestIndex,
	int32 ObjectiveIndex,
	int32 Amount
	);
	
	void CheckQuestCompleted(int32 QuestIndex);
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
