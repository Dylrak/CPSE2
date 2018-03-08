#ifndef _BALL_HPP
#define _BALL_HPP

#include "drawable.hpp"

class circle : public drawable {
private:
	sf::CircleShape cs;
public:
	circle(sf::Vector2f position, sf::Color color, float size);
};

#endif
