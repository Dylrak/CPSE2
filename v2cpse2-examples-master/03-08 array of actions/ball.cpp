#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball( sf::Vector2f position, float size, sf::Vector2f direction, sf::Color color ) :
	position{ position },
	radius{ size },
	direction{ direction },
	color{ color }
{}

void ball::draw( sf::RenderWindow & window ) {
	sf::CircleShape circle;
	circle.setRadius(radius);
	circle.setPosition(position);
	circle.setFillColor(color);
	window.draw(circle);
}

void ball::move(){
	position += direction;
}

void ball::bounce(sf::Vector2f delta) {
	direction = sf::Vector2f{ direction.x * delta.x, direction.y * delta.y };
}
