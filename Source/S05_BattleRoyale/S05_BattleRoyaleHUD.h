// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "S05_BattleRoyaleHUD.generated.h"

UCLASS()
class AS05_BattleRoyaleHUD : public AHUD
{
	GENERATED_BODY()

public:
	AS05_BattleRoyaleHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

