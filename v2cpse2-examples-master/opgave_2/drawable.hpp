#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP
#include <SFML/Graphics.hpp>

class drawable
{
private:
	static drawable* current_selection;
	sf::Shape & shape;
	
public:
	drawable(sf::Shape & shape);
	virtual void draw(sf::RenderWindow & window);
	bool collides_with_mouse(sf::Vector2i &mousePos);
	void select();
	void set_position(sf::Vector2i &delta);
};

#endif //DRAWABLE_HPP

