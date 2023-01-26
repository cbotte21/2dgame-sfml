#pragma once

#include "../sprites/dynamic/SpriteFactory.h"
#include "../sprites/dynamic/player/Player.h"
#include "../Clock.h"
#include "../sprites/DynamicSprite.h"
#include "../sprites/SpriteManager.h"
#include "../contexts/WindowContext.h"

#define LEVELS_DIR "levels/"

class LevelManager {
	Clock* clock;
	//																	(i) - render order
	Player* player;   //Obides by rules of other SpriteManagers			(4)
	SpriteManager entities;  //Can be picked up by player				(3)
	SpriteManager barriers;  //Cannot be walked through by player		(2)
	SpriteManager design; //Can be walked over. 						(1)
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
	
	/*
	std::vector<DynamicSprite*> entityCollisionReport(); //Get all entities collided with 
	std::vector<DynamicSprite*> boundaryCollisionReport(); //Get all entities collided with 
	*/
	
	void replaceEntity(DynamicSprite* entitiy); //Replace instance of entity
};
