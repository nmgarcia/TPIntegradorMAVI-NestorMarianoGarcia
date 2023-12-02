#include "Objective.h"


Objective::Objective()
{
	_enemyTexture.loadFromFile("Assets/enemy1.png");
	_enemySprite.setTexture(_enemyTexture);
	_enemySprite.setScale(0.5f, 0.5f);
	_enemySprite.setOrigin(_enemyTexture.getSize().x / 2.0f, _enemyTexture.getSize().y / 2.0f);
}

void Objective::Update()
{
}

void Objective::Draw(RenderWindow* window)
{
	_enemySprite.setPosition(175, 145);
	window->draw(_enemySprite);

	_enemySprite.setPosition(625, 145);
	window->draw(_enemySprite);

	_enemySprite.setPosition(150, 418);
	window->draw(_enemySprite);

	_enemySprite.setPosition(650, 418);
	window->draw(_enemySprite);

	_enemySprite.setPosition(400, 450);
	window->draw(_enemySprite);
}

bool Objective::IsActive() {
	return _isActive;
}

bool Objective::IsAlive() {
	return _isAlive;
}

void Objective::Activate() {
	_isActive = true;
}

void Objective::SetAsNotAlive() {
	_isAlive = false;
}
