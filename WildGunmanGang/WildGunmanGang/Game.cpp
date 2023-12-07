#include "Game.h"

Game::Game(int height, int width, string title) 
{
	_objectivesAmount = Data::ObjectivesPositions.size();
	_window = new RenderWindow(VideoMode(height, width, 32), title);
	_window->setFramerateLimit(60);
	_window->setMouseCursorVisible(false);

	_player = new Player(Data::LivesAmount);
	_points = 0;

	SetScene();
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
					Shoot();
				}
				break;
		}
	}
}

void Game::UpdateGame()
{
	Vector2i mousePosition = Mouse::getPosition(*_window);
	_player->SetPosition(mousePosition.x, mousePosition.y);

	_objectiveManager.UpdateAll();
}

void Game::DrawGame()
{
	//Layer Order:
	//0: Enemies
	DrawObjectives();

	//1: Background
	_window->draw(_backgroundSprite);

	//2: Windows based on enemies
	DrawWindows();

	//3: Top
	_window->draw(_topSprite);

	//4: Player
	_player->Draw(_window);	
}

void Game::SetUI()
{
}

void Game::SetScene()
{
	_backgroundTexture.loadFromFile(Data::AssetsPath[Background]);
	float scaleX = _window->getSize().x / (float)_backgroundTexture.getSize().x;
	float scaleY = _window->getSize().y / (float)_backgroundTexture.getSize().y;

	_backgroundSprite = Common::SetSprite(
		_backgroundTexture,
		scaleX, scaleY
	);

	_topTexture.loadFromFile(Data::AssetsPath[Top]);
	scaleX = _window->getSize().x / (float)_topTexture.getSize().x;
	scaleY = _window->getSize().y / (float)_topTexture.getSize().y;
	
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
}

void Game::Shoot() {
	

	//Check collisions
	Vector2i crossHairPosition = _player->GetPosition(*_window);

	Enum objectiveShooted = _objectiveManager.ObjectiveCollided(crossHairPosition);

	switch (objectiveShooted)
	{
		case None:
			break;
		case Innocent:			
			_player->LooseLife();
			break;
		case Enemy:
			_points++;			
			//TODO: Update visual points
			break;
	}

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

Game::~Game()
{
	delete _window;
}