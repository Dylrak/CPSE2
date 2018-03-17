#include <SFML/Graphics.hpp>
#include "circle.hpp"

circle::circle(sf::Vector2f position, sf::Color color, float size):
	drawable{ cs }
{
	cs.setPosition(position);
	cs.setFillColor(color);
	cs.setRadius(size);
}
std::string circle::name = "circle ";

std::string circle::print() {
	return name << cs.getPosition() << cs.getFillColor() << cs.getRadius() << '\n';
}