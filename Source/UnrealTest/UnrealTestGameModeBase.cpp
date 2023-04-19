// Copyright Epic Games, Inc. All Rights Reserved.


#include "UnrealTestGameModeBase.h"
#include "Student.h"
#include <memory>


AUnrealTestGameModeBase::AUnrealTestGameModeBase(const FObjectInitializer& ObjectInitializer)
	: AGameModeBase(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello,UnrealTest"));

	UStudent* Student = NewObject<UStudent>();
	UClass* StudentClass = Student->GetClass();
	FName ClassName = StudentClass->GetFName();

	UE_LOG(LogTemp, Warning, TEXT("Student's classname is %s"), *ClassName.ToString());

	for (auto Property = StudentClass->PropertyLink; Property; Property = Property->PropertyLinkNext)
	{
		FString PropertyName = Property->GetName();
		FString PropertyType = Property->GetCPPType();
		if (PropertyType == "FString")
		{
			FStrProperty* StringProperty = CastField<FStrProperty>(Property);
			void* Addr = Property->ContainerPtrToValuePtr<void>(Student);
			FString PropertyValue = StringProperty->GetPropertyValue(Addr);
			UE_LOG(LogTemp, Warning, TEXT("Student's properties has %s, Type is %s, Value is %s."), *PropertyName, *PropertyType, *PropertyValue);

			StringProperty->SetPropertyValue(Addr, "XiaoZhang");
			FString PropertyValueAfterSetting = StringProperty->GetPropertyValue(Addr);
			UE_LOG(LogTemp, Warning, TEXT("Student's properties has %s, Type is %s, Value after seting is %s."), *PropertyName, *PropertyType, *PropertyValueAfterSetting);
		}
	}

	for (TFieldIterator<UFunction> IteratorOfFunction(StudentClass); IteratorOfFunction; ++IteratorOfFunction)
	{
		UFunction* Function = *IteratorOfFunction;
		FString FunctionName = Function->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Student's Functions has %s."), *FunctionName);

		for (TFieldIterator<FProperty> IteratorOfParam(Function); IteratorOfParam; ++IteratorOfParam)
		{
			FProperty* Param = *IteratorOfParam;
			FString ParamName = Param->GetName();
			FString ParamType = Param->GetCPPType();
			EPropertyFlags ParamFlags = Param->GetPropertyFlags();
			UE_LOG(LogTemp, Warning, TEXT("Student's Functions has %s, ParamType is %s, ParamName is %s, ParamFlag is %x"), *FunctionName, *ParamType, *ParamName, ParamFlags);
		}
	}

}
