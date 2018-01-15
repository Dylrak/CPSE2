#ifndef _WALL_HPP
#define _WALL_HPP

#include "drawable.hpp"

class wall : public drawable
{
public:
	wall(sf::Vector2f position, sf::Vector2f size, sf::Color = sf::Color::Green);

	void draw(sf::RenderWindow & window) override;
private:
	sf::Vector2f position, size;
	sf::Color color;
};

#endif //_WALL_HPP