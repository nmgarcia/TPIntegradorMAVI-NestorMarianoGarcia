#include "Game.h"

//Prototype
RectangleShape rectangle(Vector2f(50.f, 120.f));

Game::Game(int height, int width, string title)
{
	_window = new RenderWindow(VideoMode(height, width, 32), title);
	_window->setFramerateLimit(60);
	_window->setMouseCursorVisible(false);

	SetBackground();
}

void Game::Go()
{
	// Main Loop
	while (_window->isOpen())
	{
		ProcessEvent();
		ProcessCollisions();
		UpdateGame();
		
		_window->clear();
		DrawGame();		
		_window->display();
	}
}

void Game::ProcessEvent()
{
	Event evt;
	while (_window->pollEvent(evt)) {

		switch (evt.type)
		{
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

}

void Game::DrawGame()
{

	//Draw Scene
	_window->draw(_backgroundSprite);
	_window->draw(rectangle);

	
}

void Game::SetUI()
{
}

void Game::SetBackground()
{

}

void Game::Shoot() {

}

void Game::ProcessCollisions()
{
}

Game::~Game()
{
	delete _window;
}