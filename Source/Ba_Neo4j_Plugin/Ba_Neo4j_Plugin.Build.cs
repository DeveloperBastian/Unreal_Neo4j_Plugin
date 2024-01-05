// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Ba_Neo4j_Plugin : ModuleRules
{
	public Ba_Neo4j_Plugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Http" });
    }
}
