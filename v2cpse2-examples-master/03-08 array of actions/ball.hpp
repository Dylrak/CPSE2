#ifndef _BALL_HPP
#define _BALL_HPP

#include "drawable.hpp"

class ball : public drawable {
public:

	ball(sf::Vector2f position, float size = 30.0, sf::Vector2f direction = sf::Vector2f{-1.0, 1.0}, sf::Color color = sf::Color::Blue);

	void draw( sf::RenderWindow & window ) override;

	void move() override;

	void bounce(sf::Vector2f delta);

private:
	sf::Vector2f position;
	float radius;
	sf::Vector2f direction;
	sf::Color color;
};

#endif
