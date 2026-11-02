#pragma once

#include "CoreMinimal.h"
#include "EQuestObjectiveType.generated.h"

UENUM(BlueprintType)
enum class EQuestObjectiveType : uint8
{
	Kill            UMETA(DisplayName = "Kill"),
	Collect         UMETA(DisplayName = "Collect"),
	Interact        UMETA(DisplayName = "Interact"),
	ReachLocation   UMETA(DisplayName = "Reach Location")
};