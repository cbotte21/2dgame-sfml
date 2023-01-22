#pragma once

#include "background/Background.h"
#include "player/Rowdy.h"
#include <string>

class SpriteFactory {
	public:
		static DynamicSprite* fromString(std::string str, WindowContext* wContext, int x, int y) {
			if (str == "rowdy")
					return new Rowdy(wContext);
			if (str == "background")
					return new Background(wContext);
			return nullptr;
		}
};