#pragma once

#include <SFML/Graphics.hpp>
#include "../contexts/WindowContext.h"
#include <stdlib.h>

/*
	The point of this class it to shrink the character as he progresses along the Y-axis.
	In hopes of rendering a 3d-like 2d game.
*/

class DepthSprite : public sf::Sprite {
	WindowContext* wContext;
	void scale() { //Scales sprite based on Y-height
		sf::Sprite* sprite = this;
		//Rescale to 1
		float difference = (sprite->getScale().y != 1) ? 1.0/sprite->getScale().y : 1;
		sprite->scale(sf::Vector2f(difference, difference));
		//Scale based on height
		float scale = (sprite->getPosition().y/wContext->height);
		if (scale == 0) {
			scale = 0.001f;
		}
		std::cout << scale << std::endl;
		sprite->scale(sf::Vector2f(scale, scale));
	}
	public:
		DepthSprite(WindowContext* wContext) {
			this->wContext = wContext;
		}
		void setPosition(sf::Vector2f position) {
			sf::Sprite::setPosition(position);
			scale();
		}
};