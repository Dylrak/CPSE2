#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include "drawable.hpp"

class rectangle : public drawable
{
private:
	sf::RectangleShape shape;
public:
	rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size);
};

#endif //_RECTANGLE_HPP