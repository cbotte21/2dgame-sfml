#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../../DynamicSprite.h"

class Background : public DynamicSprite {
	public:
		Background(WindowContext* wContext, sf::Color color) : DynamicSprite::DynamicSprite(wContext) {
			//Finalize
			sf::Image image;
			image.create(wContext->width, wContext->height, color);
			sf::Texture texture;
			texture.loadFromImage(image);
			
			this->setTexture(texture);
			this->setColor(color);
		}
};
