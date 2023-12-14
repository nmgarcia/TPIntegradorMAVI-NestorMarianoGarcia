#pragma once
#include "stdafx.h"
#include "Objective.h"
#include "Data.h"

class ObjectiveManager{

	int _objectivesAmount;
	Clock _clock;
	float _visibleTime;
	bool _isAttacking;
	int _currentVisibleIndex = -1;
	int _previousVisibleIndex = -1;
	vector<unique_ptr<Objective>> _objectives;
		
	public:
		ObjectiveManager();
		void UpdateAll();
		void SetAllAsInactive();
		void SetInnocentOrEnemy();
		int GetCurrentVisibleIndex();
		void ActivateRandomObjective();
		void DrawAll(RenderWindow& window);
		Enum ObjectiveCollided(Vector2i position);
		void EnemyAttack();
		bool IsAttacking();
		void SetIsAttackingFalse();
		

};

