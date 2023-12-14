#include "Game.h"

Game::Game(int width, int height, string title) 
{
	_objectivesAmount = Data::ObjectivesPositions.size();
	_window = new RenderWindow(VideoMode(width, height + 200, 32), title);
	_window->setFramerateLimit(60);
	_window->setMouseCursorVisible(false);
	
	_player = new Player(Data::LivesAmount);
	_titleScreen = new TitleScreen(height,width);
	_points = 0;

	SetSprites();
}

void Game::Go()
{
	// Main Loop
	while (_window->isOpen())
	{
		ProcessEvents();
		ProcessCollisions();
		UpdateGame();
		
		_window->clear();
		DrawGame();
		_window->display();
	}
}

void Game::ProcessEvents()
{
	Event evt;
	while (_window->pollEvent(evt)) {

		switch (evt.type){
			case Event::Closed:
				_window->close();
				break;
			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Button::Left) {
					if (_gameStarted)
						Shoot();
					else
						_gameStarted = true;
				}
				break;
		}
	}
}

void Game::UpdateGame()
{
	//Player Crosshair position
	Vector2i mousePosition = Mouse::getPosition(*_window);
	_player->SetPosition(mousePosition.x, mousePosition.y);
	
	//Attack of enemy
	if (_objectiveManager.IsAttacking()) {
		_player->LoseLife();
		_objectiveManager.SetIsAttackingFalse();
		SetEnemyAttack();
	}

	_objectiveManager.UpdateAll();
}

void Game::DrawGame()
{
	if (!_gameStarted) {
		//Draw title screen
		_titleScreen->Draw(_window);
	}
	else {

		//Layer Order:
		//0: Enemies
		DrawObjectives();

		//1: Background
		_window->draw(_backgroundSprite);

		//2: Windows based on enemies
		DrawWindows();

		//3: Top
		_window->draw(_topSprite);

		//4: UI

		

		//5: Enemy attack
		if (_drawEnemyAttack) {
			_window->draw(_enemyAttackSprite);

			if (_enemyAttackClock.getElapsedTime().asSeconds() > 0.5f)
				_drawEnemyAttack = false;
		}
	}

	//Player
	_player->Draw(_window);
}

void Game::SetUI()
{
}

void Game::SetSprites()
{
	_backgroundTexture.loadFromFile(Data::AssetsPath[Background]);
	float scaleX = _window->getSize().x / (float)_backgroundTexture.getSize().x;
	float scaleY = (_window->getSize().y - 200) / (float)_backgroundTexture.getSize().y;

	_backgroundSprite = Common::SetSprite(
		_backgroundTexture,
		scaleX, scaleY
	);

	_topTexture.loadFromFile(Data::AssetsPath[Top]);
	scaleX = _window->getSize().x / (float)_topTexture.getSize().x;
	scaleY = (_window->getSize().y - 200) / (float)_topTexture.getSize().y;
	
	_topSprite = Common::SetSprite(
		_topTexture,
		scaleX, scaleY
	);

	_openWindowTexture.loadFromFile(Data::AssetsPath[OpenWindow]);
	_openWindowSprite = Common::SetSprite(
		_openWindowTexture,
		0.55f, 0.55f,
		_openWindowTexture.getSize().x / 2.0f, _openWindowTexture.getSize().y / 2.0f
	);

	_closedWindowTexture.loadFromFile(Data::AssetsPath[ClosedWindow]);
	_closedWindowSprite = Common::SetSprite(
		_closedWindowTexture,
		0.55f, 0.55f,
		_closedWindowTexture.getSize().x / 2.0f, _closedWindowTexture.getSize().y / 2.0f
	);

	_enemyAttackTexture.loadFromFile(Data::AssetsPath[EnemyAttack]);
	_enemyAttackSprite = Common::SetSprite(
		_enemyAttackTexture,
		0.55f, 0.55f,
		_enemyAttackTexture.getSize().x / 2.0f, _enemyAttackTexture.getSize().y / 2.0f
	);
}

void Game::Shoot() {
	
	Common::LogMessage("comienza disparo");
	//Check collisions
	Vector2i crossHairPosition = _player->GetPosition(*_window);

	Enum objectiveShooted = _objectiveManager.ObjectiveCollided(crossHairPosition);

	switch (objectiveShooted)
	{
		case None:
			break;
		case Innocent:			
			_player->LoseLife();
			break;
		case Enemy:
			_points++;			
			//TODO: Update visual points
			break;
	}

	Common::LogMessage("Termina disparo");
}

void Game::ProcessCollisions()
{
}

void Game::DrawObjectives() {	
	_objectiveManager.DrawAll(*_window);
}

void Game::DrawWindows() {

	for (int i = 0; i < _objectivesAmount; i++) {

		if (Data::ObjectivesPositions[i]._extraSpriteRequired) {

			Vector2i position = Data::ObjectivesPositions[i]._position;
			int currentVisible = _objectiveManager.GetCurrentVisibleIndex();

			if (currentVisible == i && currentVisible != -1) {

				_openWindowSprite.setPosition(position.x, position.y);
				_window->draw(_openWindowSprite);
			}
			else {
				_closedWindowSprite.setPosition(position.x, position.y);
				_window->draw(_closedWindowSprite);
			}
		}
	}
}

void Game::SetEnemyAttack() {

	Common::LogMessage("Danio recibido");	
	_drawEnemyAttack = true;
	
	FloatRect max = _enemyAttackSprite.getGlobalBounds();
	Vector2i random(rand() % (int)(_window->getSize().x - (max.width / 2)),
					rand() % (int)((_window->getSize().y - 200) - (max.height / 2)));

	_enemyAttackSprite.setPosition(random.x, random.y);
	_enemyAttackClock.restart();

}

Game::~Game()
{
	delete _window;
}