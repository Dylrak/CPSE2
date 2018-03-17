#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class drawable
{
private:
	sf::Shape & shape;
public:
	drawable(sf::Shape & shape);
	virtual void draw(sf::RenderWindow & window);
	virtual std::string print() = 0;
	bool collides_with_mouse(sf::Vector2i mousePos);
	static drawable* current_selection;
	void select();
	void set_position(sf::Vector2f new_pos);
	sf::Vector2f get_position();

};
//Printing operators
static std::string & operator<<(std::string & lhs, const sf::Vector2f & rhs) {
	std::string vector = "(" + std::to_string( (int) rhs.x) + "," + std::to_string( (int) rhs.y) + ") ";
	lhs += vector;
	return lhs;
}

static std::string & operator<<(std::string & lhs, const sf::Color & rhs) {
	const struct { const std::string name; const sf::Color color; } colors[]{
		{ "YELLOW", sf::Color::Yellow },
		{ "RED",    sf::Color::Red },
		{ "GREEN",    sf::Color::Green },
		{ "BLUE",    sf::Color::Blue }
	};
	for (auto color : colors) {
		if (rhs == color.color) {
			lhs += color.name + ' ';
			break;
		}
	}
	return lhs;
}

static std::string & operator<<(std::string & lhs, const float & rhs) {
	lhs += std::to_string((int)(rhs)) + ' ';
	return lhs;
}

static std::string & operator<<(std::string & lhs, const std::string & rhs) {
	lhs += rhs;
	return lhs;
}

static std::string & operator<<(std::string & lhs, const char & rhs) {
	lhs += rhs;
	return lhs;
}
#endif //DRAWABLE_HPP
