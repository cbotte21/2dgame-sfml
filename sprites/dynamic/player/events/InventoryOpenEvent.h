#pragma once

#include <iostream>
#include "../../../DynamicSprite.h"

class OpenEvent : public EventHandler {
	DynamicSprite* sprite;
	bool* open;
	public:
	OpenEvent(DynamicSprite* sprite, bool* open) {
		this->sprite = sprite;
		this->open = open;
	}
	void handle(sf::Event event) override {
		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
				float scale = (*open) ? .0001f : .5f;
				sprite->setScale(sf::Vector2f(scale, scale));
				*open = !*open;
			}
		}
	}
};