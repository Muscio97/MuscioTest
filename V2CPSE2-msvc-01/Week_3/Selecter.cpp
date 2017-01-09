#include "Selecter.hpp"
#include <iostream>


Selecter::Selecter()
{}

void Selecter::detect(sf::RenderWindow & window, sf::RectangleShape &object){
	
	std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y;

}

sf::Vector2f getPos() {
	
	std::cout << "Test";
	return sf::Vector2f{ 69, 69 };
}