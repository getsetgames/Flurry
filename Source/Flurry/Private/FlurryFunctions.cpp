//
//  Created by Derek van Vliet on 2015-03-25.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FlurryPrivatePCH.h"

#if PLATFORM_IOS
NSArray* GetNSStringArray(TArray<FString> FStringArray)
{
	NSMutableArray* NewArray = [NSMutableArray array];
	
	for (auto Itr(FStringArray.CreateIterator()); Itr; Itr++)
	{
		FString String = (*Itr);
		[NewArray addObject:String.GetNSString()];
	}

	return NewArray;
}
#endif

bool ValidateParams(FString Function, FString Event, TArray<FString> ParamKeys, TArray<FString> ParamValues)
{
	if (ParamKeys.Num() != ParamValues.Num())
	{
		UE_LOG(LogFlurry,Error,TEXT("%s failed for event %s because number of param keys (%i) differs from number of param values (%i)"),*Function,*Event,ParamKeys.Num(),ParamValues.Num());
		return false;
	}
	
	if (ParamKeys.Num() > 10)
	{
		UE_LOG(LogFlurry,Error,TEXT("%s failed for event %s because the number of keys (%i) can not be greater than 10"),*Function,*Event,ParamKeys.Num());
		return false;
	}
	
	if (ParamValues.Num() > 10)
	{
		UE_LOG(LogFlurry,Error,TEXT("%s failed for event %s because the number of values (%i) can not be greater than 10"),*Function,*Event,ParamValues.Num());
		return false;
	}
	
	return true;
}

void UFlurryFunctions::FlurryStartSession(FString APIKey)
{
#if PLATFORM_IOS
	[Flurry startSession:APIKey.GetNSString()];
#endif
}

void UFlurryFunctions::FlurryLogEvent(FString Event, bool Timed)
{
#if PLATFORM_IOS
	[Flurry logEvent:Event.GetNSString() timed:Timed];
#endif
}

void UFlurryFunctions::FlurryLogEventWithParam(FString Event, FString ParamKey, FString ParamValue, bool Timed)
{
#if PLATFORM_IOS
	NSDictionary* Params = [NSDictionary dictionaryWithObject:ParamValue.GetNSString() forKey:ParamKey.GetNSString()];
	[Flurry logEvent:Event.GetNSString() withParameters:Params timed:Timed];
#endif
}

void UFlurryFunctions::FlurryLogEventWithParams(FString Event, TArray<FString> ParamKeys, TArray<FString> ParamValues, bool Timed)
{
	if (ValidateParams("FlurryLogEventWithParams", Event, ParamKeys, ParamValues) == false)
		return;

#if PLATFORM_IOS
	NSDictionary* Params = [NSDictionary dictionaryWithObjects:GetNSStringArray(ParamValues) forKeys:GetNSStringArray(ParamKeys)];
	[Flurry logEvent:Event.GetNSString() withParameters:Params timed:Timed];
#endif
}

void UFlurryFunctions::FlurryEndTimedEvent(FString Event, TArray<FString> ParamKeys, TArray<FString> ParamValues)
{
	if (ValidateParams("FlurryEndTimedEvent", Event, ParamKeys, ParamValues) == false)
		return;
	
#if PLATFORM_IOS
	NSDictionary* Params = [NSDictionary dictionaryWithObjects:GetNSStringArray(ParamValues) forKeys:GetNSStringArray(ParamKeys)];
	[Flurry endTimedEvent:Event.GetNSString() withParameters:Params];
#endif
}

void UFlurryFunctions::FlurrySetDebugLogEnabled(bool Enabled)
{
#if PLATFORM_IOS
	[Flurry setDebugLogEnabled:Enabled];
#endif
}
