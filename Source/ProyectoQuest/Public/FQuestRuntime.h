#pragma once

#include "CoreMinimal.h"
#include "FQuestObjective.h"
#include "QuestDefinition.h"
#include "FQuestRuntime.generated.h"

class UQuestDefinition;

USTRUCT(BlueprintType)
struct FQuestRuntime
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName QuestID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UQuestDefinition> QuestDefinition = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestObjective> Objectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsCompleted = false;
};