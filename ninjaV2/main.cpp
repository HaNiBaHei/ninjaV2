#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Bloody Sword", sf::Style::Close | sf::Style::Default);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("animation/runrightv2.png");
	

	Player player(&playerTexture, sf::Vector2u(4, 3), 0.07f, 250.f);

	float deltaTime = 0.0f;
	sf::Clock clock;
	
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		player.Update(deltaTime);

		window.clear(sf::Color(150, 150, 150));
		player.Draw(window);
		window.display();
	}

	return 0;
}