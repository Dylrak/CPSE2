#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	position{ position },
	size { size },
	color { color },
	rectangle ( sf::RectangleShape() )
{
	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(color);
}

void wall::draw(sf::RenderWindow & window) {
	window.draw(rectangle);
}

sf::FloatRect wall::getAABB() {
	return rectangle.getGlobalBounds();
}