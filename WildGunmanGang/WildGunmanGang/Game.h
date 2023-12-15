#pragma once
#include "stdafx.h"
#include "Player.h"
#include "Objective.h"
#include "ObjectiveManager.h"
#include "Data.h"
#include "Common.h"
#include "TitleScreen.h"
#include "UIManager.h"

class Game
{
	//Main attributes
	RenderWindow* _window;
	Player* _player;
	int _objectivesAmount;
	int _points;
	ObjectiveManager _objectiveManager;
	float _visibleTime;
	TitleScreen* _titleScreen;
	bool _gameStarted;
	bool _gameOver = false;
	UIManager _uiManager;

	//Textures and sprites
	Texture _backgroundTexture;
	Sprite _backgroundSprite;
	Texture _topTexture;
	Sprite _topSprite;
	Texture _openWindowTexture;
	Sprite _openWindowSprite;
	Texture _closedWindowTexture;
	Sprite _closedWindowSprite;
	Texture _enemyAttackTexture;
	Sprite _enemyAttackSprite;
	bool _drawEnemyAttack = false;
	Clock _enemyAttackClock;

	//Main structure
	void ProcessEvents();
	void UpdateGame();
	void DrawGame();
	void InitializeGame();

	//Aux functions
	void SetUI();
	void SetSprites();
	void Shoot();
	void SetEnemyAttack();
	void GameOver();
	
	//Draw functions
	void DrawObjectives();
	void DrawWindows();

	public:
		Game(int width, int height, string title);
		void Go();		
		~Game();
};

