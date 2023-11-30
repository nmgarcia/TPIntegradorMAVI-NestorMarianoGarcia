#pragma once
#include "stdafx.h"

class Game
{
	RenderWindow* _window;
	Texture _backgroundTexture;
	Sprite _backgroundSprite;

	void ProcessEvent();
	void UpdateGame();
	void DrawGame();
	void SetUI();

	void SetBackground();
	void Shoot();
	void ProcessCollisions();

	public:
		Game(int height, int width, string title);
		void Go();		
		~Game();
};

