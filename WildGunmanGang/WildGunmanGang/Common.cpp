#include "Common.h"

Sprite Common::SetSprite(Texture& texture)
{
	Sprite sprite;
	sprite.setTexture(texture);
	return sprite;
}

Sprite Common::SetSprite(Texture& texture, float scaleX, float scaleY)
{
	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(scaleX, scaleY);
	return sprite;
}

Sprite Common::SetSprite(Texture& texture, float scaleX, float scaleY, float originX, float originY)
{
	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(scaleX, scaleY);
	sprite.setOrigin(originX, originY);
	return sprite;
}

void Common::LogMessage(string message) {
	cout << message << endl;
}
