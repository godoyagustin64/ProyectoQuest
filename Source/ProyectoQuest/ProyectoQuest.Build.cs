// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProyectoQuest : ModuleRules
{
	public ProyectoQuest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ProyectoQuest",
			"ProyectoQuest/Variant_Platforming",
			"ProyectoQuest/Variant_Platforming/Animation",
			"ProyectoQuest/Variant_Combat",
			"ProyectoQuest/Variant_Combat/AI",
			"ProyectoQuest/Variant_Combat/Animation",
			"ProyectoQuest/Variant_Combat/Gameplay",
			"ProyectoQuest/Variant_Combat/Interfaces",
			"ProyectoQuest/Variant_Combat/UI",
			"ProyectoQuest/Variant_SideScrolling",
			"ProyectoQuest/Variant_SideScrolling/AI",
			"ProyectoQuest/Variant_SideScrolling/Gameplay",
			"ProyectoQuest/Variant_SideScrolling/Interfaces",
			"ProyectoQuest/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
