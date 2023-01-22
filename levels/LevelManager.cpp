#include "LevelManager.h"

void LevelManager::onTick() {
	player->onTick();
	entities.onTick();
	clock->onTick();
}

void LevelManager::onEvent(sf::Event event) {
	player->onEvent(event);
	entities.onEvent(event);
}

void LevelManager::render(sf::RenderWindow* window) { //TODO: Should render based on Y-AXIS
	window->clear();
	entities.draw(window);
	window->draw(*player);	
	window->display();
}
	
void LevelManager::load(std::string filename) { //Populate SpriteManagers from leveldata
	player = SpriteFactory::fromString("rowdy", wContext, 0, 0);
	entities.add(SpriteFactory::fromString("background", wContext, 0, 0));
}

std::vector<DynamicSprite*> LevelManager::collisionReport() { //Get all entities collided with 
	return *(new std::vector<DynamicSprite*>);
}

void LevelManager::replaceEntity(DynamicSprite* entitiy) { //Replace instance of entity

}