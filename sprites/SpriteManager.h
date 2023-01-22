#pragma once
#include <SFML/Graphics.hpp>

class SpriteManager {
	std::vector<DynamicSprite*> sprites; //TODO: BREAKUP -> players, entities. Will allow for player collision detection. Entity { canPickup: bool }
	public:
		void onEvent(sf::Event event) {
			for (DynamicSprite* sprite : sprites) {
				sprite->onEvent(event);
			}
		}
		void onTick() {
			for (DynamicSprite* sprite : sprites) {
				sprite->onTick();
			}
		}
		void add(DynamicSprite* sprite) {
			sprites.push_back(sprite);
		}
		void draw(sf::RenderWindow* window) {
			for (DynamicSprite* sprite : sprites) {
				window->draw(*sprite);
			}
		}
};