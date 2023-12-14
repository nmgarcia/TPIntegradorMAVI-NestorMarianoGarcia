#pragma once
#include "stdafx.h"
#include "Data.h";
#include "Common.h"

class Player{
	Texture _crossTexture;
	Sprite _crossSprite;
	int _livesAmount;

	public: 
		Player(int livesAmount);
		void SetPosition(int x, int y);
		Vector2i GetPosition(RenderWindow& window);
		void Draw(RenderWindow* window);
		void LoseLife();
		int GetLivesAmount();
};

