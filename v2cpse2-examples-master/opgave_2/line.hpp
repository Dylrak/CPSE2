#ifndef _LINE_HPP
#define _LINE_HPP

#include "drawable.hpp"

class line : public drawable
{
private:
	sf::RectangleShape shape;
public:
	line(sf::Vector2f position, sf::Color color, sf::Vector2f size);
	void draw(sf::RenderWindow & window) override;
};

#endif //_LINE_HPP