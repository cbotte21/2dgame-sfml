#pragma once

#include <SFML/Graphics.hpp>
#include "background/Background.h"
#include "player/Player.h"
#include <string>

class SpriteFactory {
	public:
		static DynamicSprite* fromString(std::string str, WindowContext* wContext, int x, int y) {
			if (str == "player")
					return new Player(wContext, x, y);
			if (str == "background")
					return new Background(wContext, sf::Color(52, 140, 49)); //TODO: Extract bgColor
			return nullptr;
		}
};