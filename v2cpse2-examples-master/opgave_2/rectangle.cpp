#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size) :
	drawable { shape }
{
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setSize(size);
}