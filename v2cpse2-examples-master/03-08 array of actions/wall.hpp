#ifndef _WALL_HPP
#define _WALL_HPP

#include "drawable.hpp"

class rectangle : public drawable
{
private:
	sf::Vector2f position, size;
	sf::Color color;
	sf::RectangleShape shape;
public:
	rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color = sf::Color::Green);

	void draw(sf::RenderWindow & window) override;
	sf::FloatRect getAABB() override;
};

#endif //_WALL_HPP
