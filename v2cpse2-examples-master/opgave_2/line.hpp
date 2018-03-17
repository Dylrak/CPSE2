#ifndef _LINE_HPP
#define _LINE_HPP

#include "drawable.hpp"
//#include "operators.hpp"

class line : public drawable
{
private:
	static std::string name;
	sf::RectangleShape shape;
public:
	line(sf::Vector2f position, sf::Color color, sf::Vector2f size);
	void draw(sf::RenderWindow & window) override;
	std::string print() override;
};

#endif //_LINE_HPP
