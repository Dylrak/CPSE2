#include "drawable.hpp"

drawable::drawable(sf::Shape & shape) :
	shape { shape }
{}

drawable* drawable::current_selection = NULL;

bool drawable::collides_with_mouse(sf::Vector2i mousePos) {
	return shape.getGlobalBounds().contains((sf::Vector2f) mousePos);
}

void drawable::draw(sf::RenderWindow & window) {
	window.draw(shape);
}
void drawable::select() {
	current_selection = this;
}

void drawable::set_position(sf::Vector2f new_pos) {
	shape.setPosition(new_pos);
}

sf::Vector2f drawable::get_position() {
	return shape.getPosition();
}