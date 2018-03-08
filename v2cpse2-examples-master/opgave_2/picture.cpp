#include "picture.hpp"

picture::picture(sf::Vector2f position, sf::Texture image):
	image { image },
	drawable { shape }
{
	shape.setPosition(position);
	shape.setTexture(&image);
}
