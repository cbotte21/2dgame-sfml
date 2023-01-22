#pragma once

#include <iostream>
#include "../../../DynamicSprite.h"

class WalkEvent : public EventHandler {
	DynamicSprite* sprite;
	public:
	WalkEvent(DynamicSprite* sprite) {
		this->sprite = sprite;
	}
	void handle(sf::Event event) override {
		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				sf::Vector2f oldPosition = sprite->getPosition();
				sprite->setPosition(sf::Vector2f(oldPosition.x-1, oldPosition.y));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { //Use if instead of else if, allows diagonal movement on tick
				sf::Vector2f oldPosition = sprite->getPosition();
				sprite->setPosition(sf::Vector2f(oldPosition.x+1, oldPosition.y));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				sf::Vector2f oldPosition = sprite->getPosition();
				sprite->setPosition(sf::Vector2f(oldPosition.x, oldPosition.y-1));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				sf::Vector2f oldPosition = sprite->getPosition();
				sprite->setPosition(sf::Vector2f(oldPosition.x, oldPosition.y+1));
			}
		}
	}
};