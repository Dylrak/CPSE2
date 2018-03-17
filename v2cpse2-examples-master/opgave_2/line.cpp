#include "line.hpp"

line::line(sf::Vector2f position, sf::Color color, sf::Vector2f size) :
	drawable{ shape }
{
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setSize(size);
}
std::string line::name = "line ";
void line::draw(sf::RenderWindow & window) {
	sf::Vertex line[] = {
		sf::Vertex(shape.getPosition(), shape.getFillColor()),
		sf::Vertex(shape.getPosition() + shape.getSize(), shape.getFillColor())
	};
	window.draw(line, 2, sf::Lines);
}

std::string line::print() {
	return name << shape.getPosition() << shape.getFillColor() << shape.getSize() << '\n';
}