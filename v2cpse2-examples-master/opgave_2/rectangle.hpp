#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include "drawable.hpp"
//#include "operators.hpp"

class rectangle : public drawable
{
private:
	static std::string name;
	sf::RectangleShape shape;
public:
	rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size);
	std::string print() override;
};

#endif //_RECTANGLE_HPP

