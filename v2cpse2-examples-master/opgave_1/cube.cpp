#include "cube.hpp"

cube::cube(sf::Vector2f position, float size, sf::Color color) :
	position { position },
	size { size },
	color { color },
	rectangle { sf::RectangleShape() }
{
	rectangle.setSize(sf::Vector2f(size, size));
	rectangle.setPosition(position);
	rectangle.setFillColor(color);
}

void cube::draw(sf::RenderWindow & window) {
	window.draw(rectangle);
}

sf::FloatRect cube::getAABB() {
	return rectangle.getGlobalBounds();
}
void cube::move(sf::Vector2f delta) {
	position += delta;
	rectangle.setPosition(position);
}