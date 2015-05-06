//
//  Created by Derek van Vliet on 2015-03-25.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ModuleManager.h"

class IFlurry : public IModuleInterface
{

public:

	static inline IFlurry& Get()
	{
		return FModuleManager::LoadModuleChecked< IFlurry >( "Flurry" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "Flurry" );
	}
};

