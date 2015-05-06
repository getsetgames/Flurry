//
//  Created by Derek van Vliet on 2015-03-25.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FlurryPrivatePCH.h"

DEFINE_LOG_CATEGORY(LogFlurry);

#define LOCTEXT_NAMESPACE "Flurry"

class FFlurry : public IFlurry
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FFlurry, Flurry )

void FFlurry::StartupModule()
{
}


void FFlurry::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
