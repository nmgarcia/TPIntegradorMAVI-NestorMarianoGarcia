#pragma once
#include "stdafx.h"

class Position
{
	public:
		Position(Vector2i position,bool extraSpriteRequired);
		Vector2i _position;
		bool _extraSpriteRequired;

};

