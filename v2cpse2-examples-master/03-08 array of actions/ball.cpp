#include <SFML/Graphics.hpp>
#include "ball.hpp"

circle::circle( sf::Vector2f position, float size, sf::Vector2f direction, sf::Color color ) :
	position{ position },
	radius{ size },
	direction{ direction },
	color{ color },
	cs{ sf::CircleShape() }
{
	cs.setRadius(radius);
	cs.setPosition(position);
	cs.setFillColor(color);
}

void circle::draw( sf::RenderWindow & window ) {
	window.draw(cs);
}

sf::FloatRect circle::getAABB() {
	return cs.getGlobalBounds();
}

void circle::collide(std::vector<drawable*> objects) {
	sf::Vector2f collisionPosition = sf::Vector2f(position.x, position.y + direction.y);
	cs.setPosition(collisionPosition);
	for (auto & object : objects) {
		if (object != this && getAABB().intersects(object->getAABB())) {
			direction = sf::Vector2f(direction.x, -direction.y);
			break;
		}
	}
	collisionPosition = sf::Vector2f(position.x + direction.x, position.y);
	cs.setPosition(collisionPosition);
	for (auto & object : objects) {
		if (object != this && getAABB().intersects(object->getAABB())) {
			direction = sf::Vector2f(-direction.x, direction.y);
			break;
		}
	}
	cs.setPosition(position);
}

void circle::move(){
	position += direction;
	cs.setPosition(position);
}

void circle::bounce(sf::Vector2f delta) {
	direction = sf::Vector2f{ direction.x * delta.x, direction.y * delta.y };
}
