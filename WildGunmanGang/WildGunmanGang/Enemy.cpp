#include "Enemy.h"


Enemy::Enemy()
{
	_enemyTexture.loadFromFile("Assets/enemy1.png");
	_enemySprite.setTexture(_enemyTexture);
	_enemySprite.setScale(0.5f, 0.5f);
	_enemySprite.setOrigin(_enemyTexture.getSize().x / 2.0f, _enemyTexture.getSize().y / 2.0f);
}

void Enemy::Draw(RenderWindow* window)
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
