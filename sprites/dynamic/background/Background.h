#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../../DynamicSprite.h"

class Background : public DynamicSprite {
	public:
		Background(WindowContext* wContext, sf::Color color) : DynamicSprite::DynamicSprite(wContext) {
			//Finalize
			this->setPosition(sf::Vector2f(0, 0));
		}
};
