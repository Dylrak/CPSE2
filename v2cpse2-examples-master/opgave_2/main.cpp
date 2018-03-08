#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "cube.hpp"
#include "rectangle.hpp"


int main( int argc, char *argv[] ){
	std::cout << "Starting application opgave_1\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	
	circle my_ball{ sf::Vector2f{ 320.0, 240.0 } };
	cube my_cube{ sf::Vector2f{ 80.0, 60.0 } };

	float wall_thickness = 10.0;

	std::vector<drawable*> objects {
		&my_ball,
		&my_cube,
	};

	while (window.isOpen()) {

		window.clear();
		for (auto & object : objects) {
			object->draw(window);
		}
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;
}

