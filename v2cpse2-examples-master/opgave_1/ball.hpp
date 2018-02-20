#ifndef _BALL_HPP
#define _BALL_HPP

#include "drawable.hpp"

class ball : public drawable {
private:
	sf::Vector2f position;
	sf::Vector2f direction;
	sf::Color color;
	float radius;
	sf::CircleShape circle;
public:
	ball(sf::Vector2f position, float size = 30.0, sf::Vector2f direction = sf::Vector2f{-1.0, 1.0}, sf::Color color = sf::Color::Blue);

	void draw( sf::RenderWindow & window ) override;
	sf::FloatRect getAABB() override;

	void collide(std::vector<drawable*> objects);
	void move();
	void bounce(sf::Vector2f delta);
};

#endif
