#include "Player.h"

Player::Player(int livesAmount)
{
	_livesAmount = livesAmount;
	_crossTexture.loadFromFile(Data::AssetsPath[Crosshair]);
	_crossSprite = Common::SetSprite(
		_crossTexture,
		0.3f, 0.3f,
		_crossTexture.getSize().x / 2.0f, _crossTexture.getSize().y / 2.0f);
}

void Player::SetPosition(int x, int y)
{
	_crossSprite.setPosition(x, y);
}

Vector2i Player::GetPosition(RenderWindow& window)
{	
	return Mouse::getPosition(window);
}

void Player::Draw(RenderWindow* window)
{
	window->draw(_crossSprite);
}

void Player::LooseLife(){
	_livesAmount--;
}
