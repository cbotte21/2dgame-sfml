#pragma once

#include <iostream>
#include "../../../DynamicSprite.h"

class RotateEvent : public EventHandler {
	DynamicSprite* sprite;
	sf::Texture *left, *right;
	public:
	RotateEvent(DynamicSprite* sprite, sf::Texture* left, sf::Texture* right) {
		this->sprite = sprite;
		this->left = left;
		this->right = right;
	}
	void handle(sf::Event event) override {
		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				sprite->setTexture(*left);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				sprite->setTexture(*right);
			}
		}
	}
};