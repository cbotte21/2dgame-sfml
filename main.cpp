#include <SFML/Graphics.hpp>
#include <iostream>

#include "contexts/WindowContext.h"
#include "sprites/dynamic/player/Rowdy.h"
#include "sprites/dynamic/background/Background.h"
#include "sprites/SpriteManager.h"
#include "Clock.h"

#define FRAMERATE_LIMIT 60
#define GAME_NAME "Cody Botte"
#define DEFAULT_WIDTH 1400
#define DEFAULT_HEIGHT 900

int main()
{
    //Game values
    sf::Color bgColor(255, 255, 255);
	int fps = FRAMERATE_LIMIT;
    Clock clock(&fps);
	WindowContext wContext(DEFAULT_WIDTH, DEFAULT_HEIGHT);

    //Init window	
    sf::RenderWindow window(sf::VideoMode(wContext.width, wContext.height), GAME_NAME);
    window.setFramerateLimit(FRAMERATE_LIMIT);

    //Init sprites TODO: Should be done by level creator
	SpriteManager spriteManager;
	
    Rowdy rowdy(&wContext);
    Background background(&wContext, bgColor);
	spriteManager.add(&rowdy);
	spriteManager.add(&background);

    //Game loop
    while (window.isOpen()) {
		//Custom tick logic
		clock.onTick();
		spriteManager.onTick();
		
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
			spriteManager.onEvent(event);
		}
		
		//Render
		spriteManager.render(&window);
    }

    return 0;
}