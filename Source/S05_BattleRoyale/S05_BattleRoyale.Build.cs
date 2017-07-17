// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class S05_BattleRoyale : ModuleRules
{
    //jdeo- public S05_BattleRoyale(TargetInfo Target)
    public S05_BattleRoyale(ReadOnlyTargetRules Target) : base (Target)
    {
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule", "GameplayTasks",  "HeadMountedDisplay" });
	}
}
