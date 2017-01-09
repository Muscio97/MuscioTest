#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "cube.hpp"
#include "triangle.hpp"
#include "Line.hpp"
#include <iostream>
#include <fstream>
#include <string>

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

	void operator()(){
		if( condition() ){
			work();
		}
	}
};

int main(int argc, char *argv[]) {
	std::cout << "\"Time.exe\" has a crashed\n";
	
			
			

		



	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "BALLS", sf::Style::Default, settings };

	ball		 my_ball{ sf::Vector2f{ 320.0, 240.0 }, 30.0,						sf::Color(0,0,255) };
	cube	 	 my_cube{ sf::Vector2f{ 320.0, 340.0 }, sf::Vector2f{ 30.0, 30.0},  sf::Color(0,255,255) };
	triangle my_triangle{ sf::Vector2f{ 200.0, 200.0 }, 50.0,						sf::Color(0,255,0) };
	line		 my_line{ sf::Vector2f{ 320.0, 200.0 }, sf::Vector2f{ 80.0, 3.0 }, sf::Color(255,0,0), 270.0};

	action actions[] = {
		action(			sf::Mouse::Right,     [&](){ my_ball.jump( sf::Mouse::getPosition( window )); })
	};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		my_ball.draw(window);
		my_cube.draw(window);
		my_triangle.draw(window);
		my_line.draw(window);
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










