#ifndef _BALL_HPP
#define _BALL_HPP

#include "drawable.hpp"
//#include "operators.hpp"

class circle : public drawable {
private:
	static std::string name;
	sf::CircleShape cs;
public:
	circle(sf::Vector2f position, sf::Color color, float size);
	virtual std::string print() override;
};

#endif
