#include "Player.h"

Player::Player()
{
	_crossTexture.loadFromFile("Assets/crosshair.png");
	_crossSprite.setTexture(_crossTexture);
	_crossSprite.setScale(0.5f, 0.5f);
	_crossSprite.setOrigin(_crossTexture.getSize().x / 2.0f, _crossTexture.getSize().y / 2.0f);
}

void Player::SetPosition(int x, int y)
{
	_crossSprite.setPosition(x, y);
}

void Player::Draw(RenderWindow* window)
{
	window->draw(_crossSprite);
}
