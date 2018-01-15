#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "cube.hpp"
#include "wall.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}
	action(
		
	) :
		condition(

		),
		work(work)
	{}
	//Unconditional action: always runs
	action(
		std::function< void() > work
	) :
		condition(
			[]()->bool { return true; }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};

int main( int argc, char *argv[] ){
	std::cout << "Starting application opgave_1\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	
	ball my_ball{ sf::Vector2f{ 320.0, 240.0 } };
	cube my_cube{ sf::Vector2f{ 80.0, 60.0 } };
	float wall_thickness = 10.0;
	wall my_walls[] = {
		wall{ sf::Vector2f { 0.0, 0.0 }, sf::Vector2f{640.0, wall_thickness } },
		wall{ sf::Vector2f{ 0.0, 0.0 }, sf::Vector2f{ wall_thickness, 480.0 } },
		wall{ sf::Vector2f{ (float) 640.0 - wall_thickness, 0.0 }, sf::Vector2f{ 640.0, 480.0 } }, //For some reason doing (float - float) returns double so we cast it to float again.
		wall{ sf::Vector2f{ 0.0, (float) 480.0 - wall_thickness }, sf::Vector2f{ 640.0, 480.0 } }
	};

	action actions[] = {
		action( sf::Keyboard::Left,  [&](){ my_cube.move( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ my_cube.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ my_cube.move( sf::Vector2f(  0.0, -1.0 )); }),
		action( sf::Keyboard::Down,  [&](){ my_cube.move( sf::Vector2f(  0.0, +1.0 )); }),

		action([&]() { my_ball.move(); })
	};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		my_ball.draw( window );
		my_cube.draw( window );
		for (auto & wall : my_walls) {
			wall.draw(window);
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

