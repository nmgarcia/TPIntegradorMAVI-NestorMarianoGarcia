#include "TitleScreen.h"

TitleScreen::TitleScreen( int width, int height ){
	_screenTexture.loadFromFile(Data::AssetsPath[TitleScreenEnum]);
	_screenSprite = Common::SetSprite(
		_screenTexture,
		(width+200)/ (float)_screenTexture.getSize().x, (height)/ (float)_screenTexture.getSize().y
	);
}

TitleScreen::~TitleScreen()
{

}

void TitleScreen::Draw(RenderWindow* window)
{
	window->draw(_screenSprite);
}
