#pragma once
#include "stdafx.h"
#include "Player.h"
#include "Objective.h"
#include "ObjectiveManager.h"
#include "Data.h"

class Game
{
	//Main attributes
	RenderWindow* _window;
	Player* _player;
	int _objectivesAmount;
	Objective* _objectives;
	ObjectiveManager _objectiveManager;
	Clock _clock;
	float _visibleTime;

	//Textures and sprites
	Texture _backgroundTexture;
	Sprite _backgroundSprite;
	Texture _topTexture;
	Sprite _topSprite;
	Texture _openWindowTexture;
	Sprite _openWindowSprite;
	Texture _closedWindowTexture;
	Sprite _closedWindowSprite;

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
	void DrawObjectives();
	void DrawWindows();

	public:
		Game(int height, int width, string title);
		void Go();		
		~Game();
};

