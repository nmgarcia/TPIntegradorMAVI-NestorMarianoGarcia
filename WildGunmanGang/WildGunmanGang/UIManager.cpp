#include "UIManager.h"

UIManager::UIManager()
{
	_font.loadFromFile(Data::AssetsPath[FontEnum]);
	
	_pointsText.setFont(_font);
	_pointsText.setCharacterSize(50.0f);
	_pointsText.setPosition(500, 725);
	_pointsText.setOutlineColor(Color::Red);
	_pointsText.setOutlineThickness(4.0f);

	_livesText.setFont(_font);
	_livesText.setCharacterSize(50.0f);
	_livesText.setPosition(500, 625);
	_livesText.setOutlineColor(Color::Red);
	_livesText.setOutlineThickness(4.0f);

	_maviText.setFont(_font);
	_maviText.setCharacterSize(35.0f);
	_maviText.setPosition(50, 725);
	_maviText.setOutlineColor(Color::Red);
	_maviText.setOutlineThickness(4.0f);

	_myNameText.setFont(_font);
	_myNameText.setCharacterSize(35.0f);
	_myNameText.setPosition(50, 625);
	_myNameText.setOutlineColor(Color::Red);
	_myNameText.setOutlineThickness(4.0f);

	_loseText.setFont(_font);
	_loseText.setCharacterSize(70.0f);
	_loseText.setPosition(200,200);
	_loseText.setFillColor(Color::Red);
	_loseText.setOutlineColor(Color::White);
	_loseText.setOutlineThickness(5.0f);
}

UIManager::~UIManager()
{
}

void UIManager::Draw(RenderWindow* window, int points, int lives, bool gameOver)
{
	_pointsText.setString("Puntos: " + to_string(points));
	window->draw(_pointsText);

	_livesText.setString("Vidas: " + to_string(lives));
	window->draw(_livesText);

	_maviText.setString("TP Integrador\nMAV1");
	window->draw(_maviText);

	_myNameText.setString("Nestor Mariano\nGarcia");
	window->draw(_myNameText);

	if (gameOver) {
		_loseText.setString("Game Over\nPuntaje: " + to_string(points));
		window->draw(_loseText);
	}
}
