#pragma once

#include "../sprites/dynamic/SpriteFactory.h"
#include "../Clock.h"
#include "../sprites/DynamicSprite.h"
#include "../sprites/SpriteManager.h"
#include "../contexts/WindowContext.h"

class LevelManager {
	Clock* clock;
	DynamicSprite* player;   //Obides by rules of other SpriteManagers
	SpriteManager entities;  //Can be picked up by player
	WindowContext* wContext;
	public:
	LevelManager(WindowContext* wContext, int* fps) {
			this->wContext = wContext;
			clock = new Clock(fps);
	}
	
	void onTick();
	void onEvent(sf::Event event);
	
	void render(sf::RenderWindow* window);
	void load(std::string filename); //Populate SpriteManagers from leveldata
	std::vector<DynamicSprite*> collisionReport(); //Get all entities collided with 
	void replaceEntity(DynamicSprite* entitiy); //Replace instance of entity
};
