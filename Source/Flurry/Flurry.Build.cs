//
//  Created by Derek van Vliet on 2015-03-25.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class Flurry : ModuleRules
	{
		public Flurry(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					"Developer/Flurry/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine"
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
							
			if (Target.Platform == UnrealTargetPlatform.IOS) {
				var LibDir = Path.Combine(ModuleDirectory,"..","..","lib","iOS");
				PrivateIncludePaths.Add(LibDir);

				var Lib = Path.Combine(LibDir,"libFlurry_6.3.0.a");
				PublicAdditionalLibraries.Add(Lib);
			}
		}
	}
}
