#include "drawable.hpp"

drawable::drawable(sf::Shape & shape) :
	shape { shape }
{}

bool drawable::collides_with_mouse(sf::Vector2i &mousePos) {
	return shape.getGlobalBounds().contains((sf::Vector2f) mousePos);
}

void drawable::draw(sf::RenderWindow & window) {
	window.draw(shape);
}
void drawable::select() {
	current_selection = this;
}

void drawable::set_position(sf::Vector2i &new_pos) {
	shape.setPosition((sf::Vector2f) new_pos);
}