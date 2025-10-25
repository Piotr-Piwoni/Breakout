#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "TimeUtils.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Breakout");
	window.setFramerateLimit(60);

	GameManager gameManager(&window);
	gameManager.initialize();

	sf::Clock clock;
	float deltaTime;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.scancode == sf::Keyboard::Scan::Escape)
					window.close();

				gameManager.handleInput(event.key);
			}
		}

		deltaTime = clock.restart().asSeconds();
		deltaTime *= TimeUtils::GetTimeScale();

		gameManager.update(deltaTime);

		window.clear();
		gameManager.render();
		window.display();
	}

	return 0;
}
