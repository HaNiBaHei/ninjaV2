#pragma once
#include <SFML/Graphics.hpp>
#include "collider.h"
class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();

	void Draw(sf::RenderWindow& window);
	collider GetCollider() { return collider(body); }

private:
	sf::RectangleShape body;
};

