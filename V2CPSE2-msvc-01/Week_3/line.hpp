#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>

class line {
public:

	line(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color(255, 255, 255), float rotation = 45);

	void draw(sf::RenderWindow & window) const;

private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	float rotation;
};

#endif
