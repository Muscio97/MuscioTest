#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "cube.hpp"

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

int main( int argc, char *argv[] ){
	std::cout << "Starting application Deimos\n";

	unsigned int window_width = 640;
	unsigned int window_height = 480;
	sf::RenderWindow window{ sf::VideoMode{ window_width, window_height }, "MLG BOOB BOUNCE SIMULATOR 2017" };

	
	ball my_ball	{ sf::Vector2f{ 320.0, 240.0 } , sf::Vector2f{ -10.0 , 15.0   } };
	ball ball		{ sf::Vector2f{  40.0, 240.0 } , sf::Vector2f{ 15.0 , -10.0 } };
	cube cube		{ sf::Vector2f{  40.0, 40.0  } , sf::Vector2f{ 200.0, 10.0 } };
	wall wall_top	{ sf::Vector2f{   0.0, 0.0   } , sf::Vector2f{ 640.0, 10.0 } };
	wall wall_bottom{ sf::Vector2f{   0.0, 470.0 } , sf::Vector2f{ 640.0, 10.0 } };
	wall wall_right	{ sf::Vector2f{   0.0, 0.0   } , sf::Vector2f{  10.0, 480.0 } };
	wall wall_left	{ sf::Vector2f{ 630.0, 0.0   } , sf::Vector2f{  10.0, 480.0 } };

	
	action actions[] = {
		action([] {return true; },	[&] {my_ball.move(); }),
		action([] {return true; },	[&] {ball.move(); }),
		action(sf::Keyboard::Left,  [&]() { cube.move(sf::Vector2f(-10.0,  0.0)); }),
		action(sf::Keyboard::Right, [&]() { cube.move(sf::Vector2f(+10.0,  0.0)); }),
		action(sf::Keyboard::Up,    [&]() { cube.move(sf::Vector2f(0.0, -10.0)); }),
		action(sf::Keyboard::Down,  [&]() { cube.move(sf::Vector2f(0.0, +10.0)); }),
	
		
	};


	InteractClass *obj[] = { &my_ball, &ball, &cube, &wall_top, &wall_bottom, &wall_right, &wall_left };

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		
		
		for (auto & obj1 : obj) {
			for(auto & obj2 : obj){
				obj1->interact(*obj2);
			}
			obj1->draw(window);
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










