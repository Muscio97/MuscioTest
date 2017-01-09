#include <SFML/Graphics.hpp>
#include "cube.hpp"

cube::cube(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	position{ position },
	size{ size },
	color{ color }
{}

void cube::draw(sf::RenderWindow & window) const {
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color(color));
	rectangle.setSize(size);
	rectangle.setPosition(position);
	
	window.draw(rectangle);

}
