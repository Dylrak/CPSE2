#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "factory.hpp"


int main( int argc, char *argv[] ){
	std::cout << "Starting application opgave_1\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	bool selection_made = false;
	sf::Vector2i last_mouse_pos;
	factory f("Factory.txt");
	if (!f.read_drawables()) {
		sf::sleep(sf::seconds(3));
		std::cout << "Terminating application\n";
		return -1;
	}
	std::vector<drawable*> drawables = f.get_drawables();
	while (window.isOpen()) {
		window.clear();
		if (!selection_made && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			last_mouse_pos = sf::Mouse::getPosition(window);
			for (auto drawable : drawables) {
				if (drawable->collides_with_mouse(last_mouse_pos)) {
					drawable->select();
					selection_made = true;
					break;
				}
			}
		}
		if (selection_made && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			drawable* selected = drawables[0]->current_selection;
			sf::Vector2f delta = (sf::Vector2f) (sf::Mouse::getPosition(window) - last_mouse_pos);
			selected->set_position(selected->get_position() + delta);
			last_mouse_pos = sf::Mouse::getPosition(window);
		}
		else {
			selection_made = false;
		}
		for (auto drawable : drawables) {
			drawable->draw(window);
		}
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				f.set_drawables(drawables);
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}

