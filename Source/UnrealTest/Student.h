// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Student.generated.h"


enum class AAAB
{
	EEEE,
	AAAA
};
/**
 * 
 */
UCLASS()
class UNREALTEST_API UStudent : public UObject
{
	GENERATED_BODY()
public:
	UStudent() {}

	UPROPERTY()
	FString Name = "LaoWang";

	UFUNCTION()
	int32 Study(int32 param1, int32 param2);
};
