#pragma once

#include "CoreMinimal.h"
#include "EQuestObjectiveType.h"
#include "FQuestObjective.generated.h"

USTRUCT(BlueprintType)
struct FQuestObjective
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ObjectiveID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestObjectiveType ObjectiveType = EQuestObjectiveType::Collect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TargetID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RequiredAmount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentAmount = 0;
};