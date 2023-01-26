#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "../../DynamicSprite.h"
#include "events/InventoryOpenEvent.h"

#define INVENTORY_IMG "sprites/dynamic/player/textures/inventory.png"

class Inventory : public DynamicSprite {
	sf::Texture inventoryTexture;
	bool open = false;
	
	void loadTexture() {
			//Load images
			
			if (!inventoryTexture.loadFromFile(INVENTORY_IMG)) {
				std::exit(1);
			}
			
			//Texture options
			inventoryTexture.setRepeated(false);
			
			this->setTexture(inventoryTexture);
	}
	public:
		//TODO: CONTRUCTOR(wContext, columns, rows, firstSlotX, firstSlotY, VerticalSpacing, HorizontalSpacing)
		Inventory(WindowContext* wContext) : DynamicSprite(wContext) {
			loadTexture();
			
			//Add event listeners
			this->registerEventHandler(new OpenEvent(this, &open));
			
			//Calculate centering offset
			sf::FloatRect globalBounds = this->getGlobalBounds();
			int verticalOffset = globalBounds.height/4;
			int horizontalOffset = globalBounds.width/4;
			
			//Finalize
			this->setPosition(sf::Vector2f(wContext->width/2-horizontalOffset, wContext->height/2-verticalOffset));
			this->setScale(sf::Vector2f(.0001f, .0001f));
		}
};
