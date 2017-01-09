#ifndef _CUBE_HPP
#define _CUBE_HPP

#include <SFML/Graphics.hpp>
#include "InteractClass.hpp"

class cube : public InteractClass {
public:

	cube(sf::Vector2f position, sf::Vector2f size);

	void draw(sf::RenderWindow & window) const;

	void move(sf::Vector2f delta);

private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape rectangle;
};

#endif







