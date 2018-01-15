#include "cube.hpp"

cube::cube(sf::Vector2f position, float size, sf::Color color) :
	position { position },
	size { size },
	color { color }
{}

void cube::draw(sf::RenderWindow & window) {
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(size, size));
	rect.setPosition(position);
	rect.setFillColor(color);
	window.draw(rect);
}

void cube::move(sf::Vector2f delta) {
	position += delta;
}