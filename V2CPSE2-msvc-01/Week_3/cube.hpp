#ifndef _CUBE_HPP
#define _CUBE_HPP

#include <SFML/Graphics.hpp>
#include "Selecter.hpp"

class cube: public Selecter {
public:

	cube(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color(255, 255, 255));

	void draw(sf::RenderWindow & window) const;

private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape rectangle;
	sf::Color color;
};

#endif
