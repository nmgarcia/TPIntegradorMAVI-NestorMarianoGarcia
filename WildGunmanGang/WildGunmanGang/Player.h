#pragma once
#include "stdafx.h"

class Player{
	Texture _crossTexture;
	Sprite _crossSprite;

	public: 
		Player();
		void SetPosition(int x, int y);
		void Draw(RenderWindow* window);
};

