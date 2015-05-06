//
//  Created by Derek van Vliet on 2015-03-25.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "FlurryFunctions.generated.h"

UCLASS(NotBlueprintable)
class UFlurryFunctions : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (Keywords = "flurry analytics"), Category = "Flurry")
	static void FlurryStartSession(FString APIKey);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "flurry analytics"), Category = "Flurry")
	static void FlurryLogEvent(FString Event, bool Timed);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "flurry analytics"), Category = "Flurry")
	static void FlurryLogEventWithParam(FString Event, FString ParamKey, FString ParamValue, bool Timed);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "flurry analytics"), Category = "Flurry")
	static void FlurryLogEventWithParams(FString Event, TArray<FString> ParamKeys, TArray<FString> ParamValues, bool Timed);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "flurry analytics"), Category = "Flurry")
	static void FlurryEndTimedEvent(FString Event, TArray<FString> ParamKeys, TArray<FString> ParamValues);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "flurry analytics"), Category = "Flurry")
	static void FlurrySetDebugLogEnabled(bool Enabled);
};
