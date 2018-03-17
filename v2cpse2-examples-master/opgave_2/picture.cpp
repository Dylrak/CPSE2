#include "picture.hpp"

picture::picture(sf::Vector2f position, std::string filename):
	drawable{ shape },
	path { filename }
{
	image.loadFromFile(filename);
	shape.setPosition(position);
	shape.setSize((sf::Vector2f)image.getSize());
	shape.setTexture(&image);
}
std::string picture::name = "picture ";
std::string picture::print() {
	return name << shape.getPosition() << path << " \n";
}