#pragma once
#include "stdafx.h"
#include "Objective.h"

class ObjectivePool
{
	vector<Objective> objectives;
	ObjectivePool(int poolSize);
	Objective GetEnemy(float x, float y);
	void UpdateAll();
	void DrawAll(RenderWindow* window);
};

