// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealTestGameModeBase.generated.h"

/**
 * 
 */

USTRUCT()
struct FStructName
{
	GENERATED_BODY()
		FStructName() {};
	UPROPERTY()
		int32 num;
};

UCLASS()
class UNREALTEST_API AUnrealTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AUnrealTestGameModeBase(const FObjectInitializer& ObjectInitializer);

	//UPROPERTY()
	//	FStructName* name; error
	//
	// --------------------
	//UPROPERTY()          on error
	//	FStructName name; 

	//	FStructName* name;
};
