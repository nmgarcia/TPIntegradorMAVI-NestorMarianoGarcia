#pragma once
#include "stdafx.h"

class Objective{
	
	Texture _enemyTexture;
	Sprite _enemySprite;
	Vector2i _position;
	bool _isInnocent;
	bool _isActive;
	bool _isAlive;

	public:
		Objective();
		void Update();
		void Draw(RenderWindow* window);

		bool IsActive();
		void Activate();
		
		bool IsAlive();
		void SetAsNotAlive();

};

