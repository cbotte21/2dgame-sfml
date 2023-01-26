#include "LevelManager.h"

#include <iostream>
#include <fstream>
#include <string>

void LevelManager::onTick() {
	player->onTick();
	//TODO: If BARRIER contians PLAYER, move player back to open position
	entities.onTick();
	barriers.onTick();
	design.onTick();
	clock->onTick();
}

void LevelManager::onEvent(sf::Event event) {
	player->onEvent(event);
	entities.onEvent(event);
	barriers.onEvent(event);
	design.onEvent(event);
}

void LevelManager::render(sf::RenderWindow* window) { //TODO: Should render based on Y-AXIS
	window->clear();
	design.draw(window);
	window->draw(*player);
	entities.draw(window);
	window->display();
}
	
void LevelManager::load(std::string filename) { //TODO: Populate SpriteManagers from leveldata
	std::ifstream mapFile(LEVELS_DIR+filename);
	if (!mapFile.is_open()) {
		std::cout << "Could not file level file!" << std::endl;
		std::exit(1);
	}
	//Data being extracted
	std::string spriteName, x, y;
	
	//Load player
	mapFile >> spriteName;
	mapFile >> x;
	mapFile >> y;
	player = (Player*)SpriteFactory::fromString(spriteName, wContext, std::stoi(x), std::stoi(y));
	mapFile >> spriteName;
	//TODO: If spriteName != "design:" design.add(DAY_NIGHT_CYCLE(stoi(spriteName))) AND mapFile >> spriteName;
	//Load design
	for (mapFile >> spriteName; spriteName != "barriers:"; mapFile >> spriteName) {
		mapFile >> x;
		mapFile >> y;
		design.add(SpriteFactory::fromString(spriteName, wContext, std::stoi(x), std::stoi(y)));
	}
	//Load barriers
	for (mapFile >> spriteName; spriteName != "entities:"; mapFile >> spriteName) {
		mapFile >> x;
		mapFile >> y;
		barriers.add(SpriteFactory::fromString(spriteName, wContext, std::stoi(x), std::stoi(y)));
	}
	//Load entities
	for (mapFile >> spriteName; mapFile.peek() != EOF; mapFile >> spriteName) {
		mapFile >> x;
		mapFile >> y;
		entities.add(SpriteFactory::fromString(spriteName, wContext, std::stoi(x), std::stoi(y)));
	}
	entities.add(player->getInventory()); //Special case outside loop
	mapFile.close();
}

/*
std::vector<DynamicSprite*> LevelManager::collisionReport() { //Get all entities collided with 
	return *(new std::vector<DynamicSprite*>);
}

std::vector<DynamicSprite*> entityCollisionReport() { //Get all entities collided with 
	return 
}

std::vector<DynamicSprite*> boundaryCollisionReport() { //Get all entities collided with 

}
*/

void LevelManager::replaceEntity(DynamicSprite* entitiy) { //Replace instance of entity

}
