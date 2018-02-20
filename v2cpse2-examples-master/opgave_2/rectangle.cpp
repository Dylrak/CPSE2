#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	position{ position },
	size{ size },
	color{ color },
	shape(sf::RectangleShape())
{
	shape.setSize(size);
	shape.setPosition(position);
	shape.setFillColor(color);
}

void rectangle::draw(sf::RenderWindow & window) {
	window.draw(shape);
}

sf::FloatRect rectangle::getAABB() {
	return shape.getGlobalBounds();
}