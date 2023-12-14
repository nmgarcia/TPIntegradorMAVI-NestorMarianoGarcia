#pragma once
#include "stdafx.h"

/// <summary>
/// Class to be used as helper with common functions to every class to avoid duplicate code
/// </summary>
class Common
{
	public:
		static Sprite SetSprite(Texture& texture);
		static Sprite SetSprite(Texture& texture, float scaleX,float scaleY);
		static Sprite SetSprite(Texture& texture, float scaleX,float scaleY, float originX, float originY);
		static void LogMessage(string message);

};

