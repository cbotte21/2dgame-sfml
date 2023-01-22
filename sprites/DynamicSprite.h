#pragma once

#include <SFML/Graphics.hpp>
#include "DepthSprite.h"
#include "EventHandler.h"
#include "TickHandler.h"
#include <vector>
#include <iostream>

/*
	The point of this class it to dynamically resize sprites with window size.
*/

class DynamicSprite : public DepthSprite {
	std::vector<EventHandler*> eventHandlers;
	std::vector<TickHandler*> tickHandlers;
	public:
	DynamicSprite(WindowContext* wContext) : DepthSprite::DepthSprite(wContext) {}
	void registerEventHandler(EventHandler* eventHandler) {
		eventHandlers.push_back(eventHandler);
	}
	void onEvent(sf::Event event) {
		for (int i = 0; i < eventHandlers.size(); i++) {
			eventHandlers.at(i)->handle(event);
		}
	}
	void registerTickHandler(TickHandler* tickHandler) {
		tickHandlers.push_back(tickHandler);
	}
	void onTick() {
		for (int i = 0; i < tickHandlers.size(); i++) {
			tickHandlers.at(i)->handle();
		}
	}
	//TODO: Add unregister event
};