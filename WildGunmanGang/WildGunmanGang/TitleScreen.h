#pragma once
#include "stdafx.h"
#include "Common.h"
#include "Data.h"

class TitleScreen
{
	Texture _screenTexture;
	Sprite _screenSprite;
	public:
		TitleScreen(int width, int height);
		~TitleScreen();

		void Draw(RenderWindow* window );
};

