#include "Game.h"

Game::Game(int height, int width, string title)
{
	_window = new RenderWindow(VideoMode(height, width, 32), title);
	_window->setFramerateLimit(60);
	_window->setMouseCursorVisible(false);

	_player = new Player();
	_enemiesAmount = 5;
	_enemies = new Objective[_enemiesAmount];

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
}

void Game::DrawGame()
{
	//Layer Order:
	//0: Enemies
	DrawEnemies();

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
	_backgroundTexture.loadFromFile("Assets/background.png");
	_backgroundSprite.setTexture(_backgroundTexture);
	float scaleX = _window->getSize().x / (float)_backgroundTexture.getSize().x;
	float scaleY = _window->getSize().y / (float)_backgroundTexture.getSize().y;

	_backgroundSprite.setScale(scaleX, scaleY);

	_topTexture.loadFromFile("Assets/top.png");
	_topSprite.setTexture(_topTexture);
	scaleX = _window->getSize().x / (float)_topTexture.getSize().x;
	scaleY = _window->getSize().y / (float)_topTexture.getSize().y;

	_topSprite.setScale(scaleX, scaleY);

	_openWindowTexture.loadFromFile("Assets/openWindow.png");
	_openWindowSprite.setTexture(_openWindowTexture);
	_openWindowSprite.setScale(0.55f, 0.55f);
	_openWindowSprite.setOrigin(_openWindowTexture.getSize().x / 2.0f, _openWindowTexture.getSize().y / 2.0f);
}

void Game::Shoot() {
	cout<< "Position: ("<< Mouse::getPosition(*_window).x<<","<< Mouse::getPosition(*_window).y<<")" << endl;
}

void Game::ProcessCollisions()
{
}

void Game::DrawEnemies() {
	_enemies->Draw(_window);
}

void Game::DrawWindows() {
	//Use enemies to draw windows
	_openWindowSprite.setPosition(175, 145);
	_window->draw(_openWindowSprite);

	_openWindowSprite.setPosition(625, 145);
	_window->draw(_openWindowSprite);

	_openWindowSprite.setPosition(150, 418);
	_window->draw(_openWindowSprite);

	_openWindowSprite.setPosition(650, 418);
	_window->draw(_openWindowSprite);

	_openWindowSprite.setPosition(400, 450);
	_window->draw(_openWindowSprite);
}

Game::~Game()
{
	delete _window;
}