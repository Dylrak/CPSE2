#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball( sf::Vector2f position, float size, sf::Vector2f direction, sf::Color color ) :
	position{ position },
	radius{ size },
	direction{ direction },
	color{ color },
	circle{ sf::CircleShape() }
{
	circle.setRadius(radius);
	circle.setPosition(position);
	circle.setFillColor(color);
}

void ball::draw( sf::RenderWindow & window ) {
	window.draw(circle);
}

sf::FloatRect ball::getAABB() {
	return circle.getGlobalBounds();
}

void ball::collide(std::vector<drawable*> objects) {
	sf::Vector2f collisionPosition = sf::Vector2f(position.x, position.y + direction.y);
	circle.setPosition(collisionPosition);
	for (auto & object : objects) {
		if (object != this && getAABB().intersects(object->getAABB())) {
			direction = sf::Vector2f(direction.x, -direction.y);
			break;
		}
	}
	collisionPosition = sf::Vector2f(position.x + direction.x, position.y);
	circle.setPosition(collisionPosition);
	for (auto & object : objects) {
		if (object != this && getAABB().intersects(object->getAABB())) {
			direction = sf::Vector2f(-direction.x, direction.y);
			break;
		}
	}
	circle.setPosition(position);
}

void ball::move(){
	position += direction;
	circle.setPosition(position);
}

void ball::bounce(sf::Vector2f delta) {
	direction = sf::Vector2f{ direction.x * delta.x, direction.y * delta.y };
}
