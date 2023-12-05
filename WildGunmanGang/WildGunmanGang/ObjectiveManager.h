#pragma once
#include "stdafx.h"
#include "Objective.h"
#include "Data.h"

class ObjectiveManager{

	int _objectivesAmount;
	Clock _clock;
	float _visibleTime;
	int _currentVisibleIndex = -1;
	vector<unique_ptr<Objective>> _objectives;
		
	public:
		ObjectiveManager();
		void UpdateAll();
		int GetCurrentVisibleIndex();
		void ActivateRandomObjective();
		void SetCurrentObjectiveInactive();
		void DrawAll(RenderWindow& window);

};

