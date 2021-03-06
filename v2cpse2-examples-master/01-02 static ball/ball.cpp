#include <SFML/Graphics.hpp>
#include "ball.hpp"

circle::circle(sf::Vector2f position, float size) :
	position{ position },
	radius{ size }
{}

void circle::draw(sf::RenderWindow & window) const {
	sf::CircleShape circle;
	circle.setRadius( radius );
	circle.setPosition( position );
	window.draw( circle );
}
