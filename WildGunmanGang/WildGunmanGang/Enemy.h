#pragma once
#include "stdafx.h"

class Enemy{
	
	Texture _enemyTexture;
	Sprite _enemySprite;

	public:
		Enemy();
		void Draw(RenderWindow* window);

};

