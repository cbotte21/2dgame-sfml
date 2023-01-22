#include <SFML/Graphics.hpp>
#include <iostream>

#include "contexts/WindowContext.h"
#include "levels/LevelManager.h"
#include "sprites/dynamic/player/Rowdy.h"
#include "sprites/dynamic/background/Background.h"
#include "sprites/SpriteManager.h"
#include "Clock.h"

#define FRAMERATE_LIMIT 200
#define GAME_NAME "Cody Botte"
#define DEFAULT_WIDTH 1400
#define DEFAULT_HEIGHT 900

int main()
{
    //Game values
	int fps = FRAMERATE_LIMIT;

    //Init window
	WindowContext wContext(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    sf::RenderWindow window(sf::VideoMode(wContext.width, wContext.height), GAME_NAME);
    window.setFramerateLimit(FRAMERATE_LIMIT);

    //Init level
	LevelManager levelManager(&wContext, &fps);
	levelManager.load("example_level.txt");

    //Game loop
    while (window.isOpen()) {
		//Custom tick logic
		levelManager.onTick();
		
		//EventHandlers
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Resized) {
				wContext.width = event.size.width;
				wContext.height = event.size.height;
			}
			if (sf::Event::Closed) {
				window.close();
	            break;
			}
			levelManager.onEvent(event);
		}
		//Render
		levelManager.render(&window);
    }

    return 0;
}