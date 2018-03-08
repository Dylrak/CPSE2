#include "line.hpp"

line::line(sf::Vector2f position, sf::Color color, sf::Vector2f size) :
	drawable{ shape }
{
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setSize(size);
}

void line::draw(sf::RenderWindow & window) {
	sf::Vertex line[] = {
		sf::Vertex(shape.getPosition),
		sf::Vertex(shape.getSize)
	};
	window.draw(line, 2, sf::Lines);
}