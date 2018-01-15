#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	position{ position },
	size { size },
	color { color }
{}

void wall::draw(sf::RenderWindow & window) {
	sf::RectangleShape rect;
	rect.setSize(size);
	rect.setPosition(position);
	rect.setFillColor(color);
	window.draw(rect);
}