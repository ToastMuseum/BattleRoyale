// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class S05_BattleRoyaleEditorTarget : TargetRules
{
	// jdeo - public S05_BattleRoyaleEditorTarget(TargetInfo Target)
    public S05_BattleRoyaleEditorTarget(TargetInfo Target) : base (Target)
	{
		Type = TargetType.Editor;
       
        // Jdeo- Trying to fix the Module constructors error
        ExtraModuleNames.Add("S05_BattleRoyale");
    }

	//
	// TargetRules interface.
	//

    /* jdeo
	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.Add("S05_BattleRoyale");
	}
    */

}
