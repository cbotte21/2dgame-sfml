#pragma once
#include <SFML/Graphics.hpp>

class SpriteManager {
	std::vector<DynamicSprite*> sprites;
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
		void render(sf::RenderWindow* window) {
			window->clear();
			for (DynamicSprite* sprite : sprites) {
				window->draw(*sprite);
			}
			window->display();
		}
};