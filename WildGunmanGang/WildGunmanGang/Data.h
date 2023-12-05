#pragma once
#include "stdafx.h"
#include "Position.h"

enum AssetsEnum
{
Innocent,
Enemy1,
Enemy2,
OpenWindow,
ClosedWindow,
Top,
Crosshair,
Background
};

/// <summary>
/// Class to be used as database with static members to save paths and positions
/// </summary>
class Data
{
	public:
		static vector<Position> ObjectivesPositions;
		static map<AssetsEnum, string> assetsPath;
};

