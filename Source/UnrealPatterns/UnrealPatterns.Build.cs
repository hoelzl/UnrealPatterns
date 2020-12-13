// Copyright Dr. Matthias Hölzl. All Rights Reserved.

using UnrealBuildTool;

public class UnrealPatterns : ModuleRules
{
	public UnrealPatterns(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
