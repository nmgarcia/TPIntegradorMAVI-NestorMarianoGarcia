#include "Data.h"

vector<Position> Data::ObjectivesPositions = { 
	Position(Vector2i(175, 145),true),
	Position(Vector2i(625, 145),true),
	Position(Vector2i(150, 418),true),
	Position(Vector2i(650, 418),true),
	Position(Vector2i(400, 450),false),
};

map<Enum,string> Data::AssetsPath = {
	{Innocent,"Assets/innocent.png"},
	{Enemy,"Assets/enemy1.png"},
	{Enemy2,"Assets/enemy2.png"},
	{OpenWindow,"Assets/openWindow.png"},
	{ClosedWindow,"Assets/closedWindow.png"},
	{Top,"Assets/top.png"},
	{Crosshair,"Assets/crosshair.png"},
	{Background,"Assets/background.png"},
};

int Data::LivesAmount = 3;
int Data::PointsToWin = 3;
float Data::ObjectiveVisibleTime = 2.0f;

		