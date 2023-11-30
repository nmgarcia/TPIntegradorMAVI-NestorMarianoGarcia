#include "Game.h"
#include "stdafx.h"

Texture texture;
Sprite sprite;

int main() {
	
	Game myGame(800, 600, "Wild Gunman Gang");
	myGame.Go();

	return EXIT_SUCCESS;
}