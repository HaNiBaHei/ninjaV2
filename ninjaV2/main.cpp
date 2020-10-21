#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Player.h"

static const float VIEW_HEIGHT = 720.0f;
static const float VIEW_WIDGHT = 1080.0f;
// set sprite on the centor //
/*void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}*/

int main()
{
	// window screen //
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Bloody Sword", sf::Style::Close | sf::Style::Default); // setting window //
	//sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT)); // view sprite //


	sf::RectangleShape tile_1;
	tile_1.setSize(sf::Vector2f(1920, 300));
	sf::Texture tile_1Texture;
	tile_1Texture.loadFromFile("Background/dirtforest.png");
	tile_1.setTexture(&tile_1Texture);
	tile_1.setPosition(0, 850);

	// background //
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1920.0f, 780.0f));
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Background/skyforest.png");
	background.setTexture(&backgroundTexture);

	
	

	// player texture //
	sf::Texture playerTexture;
	playerTexture.loadFromFile("animation/move.png");
	

	Player player(&playerTexture, sf::Vector2u(4, 2), 0.15f, 250.f);

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
			case sf::Event::Resized:
				//ResizeView(window, view);
				break;
			}
		}

		player.Update(deltaTime);
		//view.setCenter(player.GetPosition());
		window.draw(background);
		window.draw(tile_1);
		window.clear();
		
		//window.setView(view);
		player.Draw(window);
		window.display();
	}

	return 0;
}