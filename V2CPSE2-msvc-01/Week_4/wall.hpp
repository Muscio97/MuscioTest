#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "InteractClass.hpp"

class wall : public InteractClass {
public:

	wall(sf::Vector2f position, sf::Vector2f size);

	void draw(sf::RenderWindow & window) const;
	
	void move(sf::Vector2f delta);

	sf::FloatRect getBoundingBox() const;

private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape rectangle;
};

#endif







