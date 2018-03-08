#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>

class circle {
public:

	circle( sf::Vector2f position, float size = 30.0 );

	void draw( sf::RenderWindow & window ) const;

private:
	sf::Vector2f position;
	float radius;
};

#endif
