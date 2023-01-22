#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../../DynamicSprite.h"

class Background : public DynamicSprite {
	public:
		Background(WindowContext* wContext) : DynamicSprite::DynamicSprite(wContext) {
			sf::Color color(52, 140, 49);
			//Finalize
			sf::Image image;
			image.create(wContext->width, wContext->height, color);
			sf::Texture texture;
			texture.loadFromImage(image);
			
			this->setTexture(texture);
			this->setColor(color);
		}
};
