#pragma once
#include "stdafx.h"
#include "Position.h"

enum Enum
{
	None,
	Innocent,
	Enemy,
	Enemy2,
	OpenWindow,
	ClosedWindow,
	Top,
	Crosshair,
	Background,
	EnemyAttack,
	TitleScreenEnum,
	FontEnum
};

/// <summary>
/// Class to be used as database with static members to save paths and positions
/// </summary>
class Data
{
	public:
		static int LivesAmount;
		static vector<Position> ObjectivesPositions;
		static map<Enum, string> AssetsPath;
		static float ObjectiveVisibleTime;
		
};

