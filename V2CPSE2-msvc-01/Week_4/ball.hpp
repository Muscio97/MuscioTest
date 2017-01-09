#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "InteractClass.hpp"

class ball: public InteractClass{
public:

	ball( sf::Vector2f position, sf::Vector2f delta, float size = 30.0 );

	sf::Vector2f getPos() const;
	void draw( sf::RenderWindow & window ) const;

	void move();

	void interact(InteractClass & object);


private:
	sf::CircleShape circle;
	sf::Vector2f position;
	sf::Vector2f delta;


	float size;
};

#endif







