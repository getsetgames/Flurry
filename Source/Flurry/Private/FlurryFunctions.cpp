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
#if PLATFORM_IOS
	NSArray* NSParamKeys = GetNSStringArray(ParamKeys);
	NSArray* NSParamValues = GetNSStringArray(ParamValues);
	NSDictionary* Params = [NSDictionary dictionaryWithObjects:NSParamValues forKeys:NSParamKeys];
	[Flurry logEvent:Event.GetNSString() withParameters:Params timed:Timed];
#endif
}

void UFlurryFunctions::FlurryEndTimedEvent(FString Event, TArray<FString> ParamKeys, TArray<FString> ParamValues)
{
#if PLATFORM_IOS
	NSArray* NSParamKeys = GetNSStringArray(ParamKeys);
	NSArray* NSParamValues = GetNSStringArray(ParamValues);
	NSDictionary* Params = [NSDictionary dictionaryWithObjects:NSParamValues forKeys:NSParamKeys];
	[Flurry endTimedEvent:Event.GetNSString() withParameters:Params];
#endif
}

void UFlurryFunctions::FlurrySetDebugLogEnabled(bool Enabled)
{
#if PLATFORM_IOS
	[Flurry setDebugLogEnabled:Enabled];
#endif
}
