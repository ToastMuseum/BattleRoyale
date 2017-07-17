// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "S05_BattleRoyale.h"
#include "S05_BattleRoyaleGameMode.h"
#include "S05_BattleRoyaleHUD.h"
#include "Player/FirstPersonCharacter.h"

AS05_BattleRoyaleGameMode::AS05_BattleRoyaleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_BattleRoyaleHUD::StaticClass();
}
