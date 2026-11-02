// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestComponent.h"


// Sets default values for this component's properties
UQuestComponent::UQuestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("QUEST COMPONENT C++: BEGIN PLAY"));

	AQuestGameState* QuestGameState =
		GetWorld()->GetGameState<AQuestGameState>();

	if (QuestGameState)
	{
		UE_LOG(LogTemp, Warning, TEXT("QUEST COMPONENT C++: GAMESTATE ENCONTRADO"));

		QuestGameState->OnGameplayObjectiveEvent.AddDynamic(
			this,
			&UQuestComponent::HandleGameplayObjective
		);

		UE_LOG(LogTemp, Warning, TEXT("QUEST COMPONENT C++: DELEGATE CONECTADO"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("QUEST COMPONENT C++: NO ENCONTRO QUESTGAMESTATE"));
	}
}


// Called every frame
void UQuestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UQuestComponent::FindQuestByID(
	FName QuestID,
	FQuestRuntime& QuestData,
	int32& QuestIndex
)
{
	for (int32 Index = 0; Index < ActiveQuests.Num(); ++Index)
	{
		if (ActiveQuests[Index].QuestID == QuestID)
		{
			QuestData = ActiveQuests[Index];
			QuestIndex = Index;
			return true;
		}
	}

	QuestIndex = -1;
	return false;
}

bool UQuestComponent::AddQuest(UQuestDefinition* QuestDefinition)
{
	if (!QuestDefinition)
	{
		return false;
	}

	FQuestRuntime ExistingQuest;
	int32 ExistingQuestIndex = -1;

	if (FindQuestByID(
		QuestDefinition->QuestID,
		ExistingQuest,
		ExistingQuestIndex
	))
	{
		return false;
	}

	FQuestRuntime NewQuest;

	NewQuest.QuestID = QuestDefinition->QuestID;
	NewQuest.QuestDefinition = QuestDefinition;
	NewQuest.Objectives = QuestDefinition->Objectives;
	NewQuest.bIsActive = true;
	NewQuest.bIsCompleted = false;

	const int32 NewQuestIndex = ActiveQuests.Add(NewQuest);

	
	OnQuestStarted.Broadcast(
		ActiveQuests[NewQuestIndex]
	);

	return true;
}

void UQuestComponent::HandleGameplayObjective(
	EQuestObjectiveType ObjectiveType,
	FName TargetID,
	int32 Amount
)
{
	UE_LOG(
	LogTemp,
	Warning,
	TEXT("QUEST COMPONENT C++: EVENTO RECIBIDO - TargetID: %s - Amount: %d"),
	*TargetID.ToString(),
	Amount
);
	
	for (int32 QuestIndex = 0; QuestIndex < ActiveQuests.Num(); ++QuestIndex)
	{
		FQuestRuntime& Quest = ActiveQuests[QuestIndex];

		if (!Quest.bIsActive || Quest.bIsCompleted)
		{
			continue;
		}

		for (int32 ObjectiveIndex = 0;
			 ObjectiveIndex < Quest.Objectives.Num();
			 ++ObjectiveIndex)
		{
			FQuestObjective& Objective = Quest.Objectives[ObjectiveIndex];

			if (Objective.ObjectiveType == ObjectiveType &&
				Objective.TargetID == TargetID)
			{
				UpdateObjectiveProgress(
					QuestIndex,
					ObjectiveIndex,
					Amount
				);
			}
		}
	}
}

void UQuestComponent::UpdateObjectiveProgress(
	int32 QuestIndex,
	int32 ObjectiveIndex,
	int32 Amount
)
{
	if (!ActiveQuests.IsValidIndex(QuestIndex))
	{
		return;
	}

	FQuestRuntime& Quest = ActiveQuests[QuestIndex];

	if (!Quest.bIsActive || Quest.bIsCompleted)
	{
		return;
	}

	if (!Quest.Objectives.IsValidIndex(ObjectiveIndex))
	{
		return;
	}

	FQuestObjective& Objective = Quest.Objectives[ObjectiveIndex];

	Objective.CurrentAmount = FMath::Clamp(
		Objective.CurrentAmount + Amount,
		0,
		Objective.RequiredAmount
	);
	
	UE_LOG(
	LogTemp,
	Warning,
	TEXT("QUEST C++ PROGRESO: %s -> %d/%d"),
	*Objective.ObjectiveID.ToString(),
	Objective.CurrentAmount,
	Objective.RequiredAmount
);

	OnQuestProgressChanged.Broadcast(
		ActiveQuests[QuestIndex]
	);

	CheckQuestCompleted(QuestIndex);
}

void UQuestComponent::CheckQuestCompleted(int32 QuestIndex)
{
	if (!ActiveQuests.IsValidIndex(QuestIndex))
	{
		return;
	}

	FQuestRuntime& Quest = ActiveQuests[QuestIndex];

	if (!Quest.bIsActive || Quest.bIsCompleted)
	{
		return;
	}

	for (const FQuestObjective& Objective : Quest.Objectives)
	{
		if (Objective.CurrentAmount < Objective.RequiredAmount)
		{
			return;
		}
	}

	Quest.bIsCompleted = true;
	Quest.bIsActive = false;
	
	UE_LOG(
	LogTemp,
	Warning,
	TEXT("QUEST C++ COMPLETADA: %s"),
	*Quest.QuestID.ToString()
);
	OnQuestCompleted.Broadcast(Quest);
}