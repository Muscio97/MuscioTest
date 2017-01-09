#ifndef _TRIANGLE_HPP
#define _TRIANGLE_HPP

#include <SFML/Graphics.hpp>

class triangle {
public:

	triangle(sf::Vector2f position, float size, sf::Color color = sf::Color(255, 255, 255));

	void draw(sf::RenderWindow & window) const;

	void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);

private:
	sf::Vector2f position;
	float size;
	sf::Color color;
};

#endif







