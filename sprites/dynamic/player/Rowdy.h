#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../../DynamicSprite.h"
#include "events/WalkEvent.h"
#include "events/RotateEvent.h"

#define ROWDY_LEFT "sprites/dynamic/player/textures/rowdy-left.png"
#define ROWDY_RIGHT "sprites/dynamic/player/textures/rowdy-right.png"

class Rowdy : public DynamicSprite {
	sf::Texture left, right;
	public:
		Rowdy(WindowContext* wContext) : DynamicSprite(wContext) {
			//Load images
			if (!left.loadFromFile(ROWDY_LEFT)) {
				std::exit(1);
			}
			if (!right.loadFromFile(ROWDY_RIGHT)) {
				std::exit(1);
			}
			
			//Texture options
			left.setRepeated(false);
			right.setRepeated(false);
			
			//Add event listeners
			WalkEvent* walkEvent = new WalkEvent(this);
			RotateEvent* rotateEvent = new RotateEvent(this, &left, &right);
			this->registerEventHandler(walkEvent);
			this->registerEventHandler(rotateEvent);
			
			//Finalize
			this->setTexture(left);
			this->setPosition(sf::Vector2f(0, 0));
		}
};
