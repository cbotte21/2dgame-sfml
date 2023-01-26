#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../../DynamicSprite.h"
#include "events/PlayerWalkEvent.h"
#include "events/PlayerRotateEvent.h"
#include "Inventory.h"

#define PLAYER_LEFT "sprites/dynamic/player/textures/player-left.png"
#define PLAYER_RIGHT "sprites/dynamic/player/textures/player-right.png"

//TODO: Abstract to interface (pure virtual class)

class Player : public DynamicSprite {
	sf::Texture left, right;
	Inventory* inventory;
	
	void loadTexture() {
			//Load images
			if (!left.loadFromFile(PLAYER_LEFT)) {
				std::exit(1);
			}
			if (!right.loadFromFile(PLAYER_RIGHT)) {
				std::exit(1);
			}
			
			//Texture options
			left.setRepeated(false);
			right.setRepeated(false);
			
			this->setTexture(left);
	}
	
	public:
		Player(WindowContext* wContext, int x, int y) : DynamicSprite(wContext) {
			inventory = new Inventory(wContext);
			loadTexture();
			
			//Add event listeners
			this->registerEventHandler(new WalkEvent(this));
			this->registerEventHandler(new RotateEvent(this, &left, &right));
			
			//Finalize
			this->setPosition(sf::Vector2f(x, y));
		}
		Inventory* getInventory() {
			return inventory;
		}
};
