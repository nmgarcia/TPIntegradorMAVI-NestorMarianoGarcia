#include "Data.h"

vector<Position> Data::ObjectivesPositions = { 
	Position(Vector2i(175, 145),true),
	Position(Vector2i(625, 145),true),
	Position(Vector2i(150, 418),true),
	Position(Vector2i(650, 418),true),
	Position(Vector2i(400, 450),false),
};

map<AssetsEnum,string> Data::assetsPath = {
	{Innocent,"Assets/innocent.png"},
	{Enemy1,"Assets/enemy1.png"},
	{Enemy2,"Assets/enemy2.png"},
	{OpenWindow,"Assets/openWindow.png"},
	{ClosedWindow,"Assets/closedWindow.png"},
	{Top,"Assets/top.png"},
	{Crosshair,"Assets/crosshair.png"},
	{Background,"Assets/background.png"},
};

		