#ifndef _PICTURE_HPP
#define _PICTURE_HPP

#include "drawable.hpp"

class picture : public drawable
{
private:
	sf::Texture &image;
	sf::RectangleShape shape;
public:
	picture(sf::Vector2f position, sf::Texture image);
};

#endif //_PICTURE_HPP
