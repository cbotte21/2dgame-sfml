#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class EventHandler {
	public:
		virtual void handle(sf::Event event) = 0;
};