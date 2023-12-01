#pragma once
#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
	//Main attributes
	RenderWindow* _window;
	Player* _player;
	int _enemiesAmount;
	Enemy* _enemies;

	//Textures and sprites
	Texture _backgroundTexture;
	Sprite _backgroundSprite;
	Texture _topTexture;
	Sprite _topSprite;
	Texture _openWindowTexture;
	Sprite _openWindowSprite;

	//Main structure
	void ProcessEvents();
	void UpdateGame();
	void DrawGame();
	void ProcessCollisions();
	
	//Aux functions
	void SetUI();
	void SetScene();
	void Shoot();
	
	//Draw functions
	void DrawEnemies();
	void DrawWindows();

	public:
		Game(int height, int width, string title);
		void Go();		
		~Game();
};

