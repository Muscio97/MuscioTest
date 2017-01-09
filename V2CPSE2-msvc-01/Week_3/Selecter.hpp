#ifndef SELECTER_HPP

#define SELECTER_HPP
#include <SFML/Graphics.hpp>

class Selecter
{

public:
	
	
	Selecter();
	
	void detect(sf::RenderWindow & window, sf::RectangleShape &object);

	sf::Vector2f getPos();

};
#endif // !SELECTER_HPP
