// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestGiver.h"
#include "QuestComponent.h"


// Sets default values
AQuestGiver::AQuestGiver()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQuestGiver::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestGiver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AQuestGiver::Interact_Implementation(AActor* Interactor)
{
	UE_LOG(LogTemp, Warning, TEXT("QUEST GIVER C++: INTERACT EJECUTADO"));

	if (!Interactor)
	{
		UE_LOG(LogTemp, Warning, TEXT("QUEST GIVER C++: INTERACTOR ES NULL"));
		return;
	}

	UE_LOG(
		LogTemp,
		Warning,
		TEXT("QUEST GIVER C++: INTERACTOR = %s"),
		*Interactor->GetName()
	);

	UQuestComponent* QuestComponent =
		Interactor->FindComponentByClass<UQuestComponent>();

	if (!QuestComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("QUEST GIVER C++: NO ENCONTRO QUEST COMPONENT"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("QUEST GIVER C++: QUEST COMPONENT ENCONTRADO"));

	QuestComponent->AddQuest(QuestDefinition);
}

