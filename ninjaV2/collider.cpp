#include "collider.h"

collider::collider(sf::RectangleShape& body) :
	body(body)
{

}

collider::~collider()
{

}

bool collider::CheckCollistion(collider& other, float push)
{
	sf::Vector2f otherPostion = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPostion = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPostion.x - thisPostion.x;
	float deltaY = otherPostion.y - thisPostion.y;
	float intersecX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersecY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersecX < 0.0f && intersecY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);   // 0 - 1//

		if (intersecX > intersecY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersecX * (1.0f - push), 0.0f);
				other.Move(intersecX * push, 0.0f);
			}
			else
			{
				Move(-intersecX * (1.0f - push), 0.0f);
				other.Move(intersecX * push, 0.0f);
			}
		}
		else
		{
			if (deltaX > 0.0f)
			{
				Move(0.0f, intersecY * (1.0f - push));
				other.Move(0.0f, intersecY * push);
			}
			else
			{
				Move(0.0f, -intersecY * (1.0f - push));
				other.Move(0.0f, intersecY * push);
			}
		}

		return true;
	}

	return false;
}