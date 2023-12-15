#pragma once
#include "stdafx.h"
#include "Data.h"

class UIManager {
	
	Font _font;
	Text _pointsText;
	Text _livesText;
	Text _winText;
	Text _loseText;
	Text _maviText;
	Text _myNameText;
	
	public:
		UIManager();
		~UIManager();
		void Draw(RenderWindow* window, int points, int lives, bool gameOver);
};

