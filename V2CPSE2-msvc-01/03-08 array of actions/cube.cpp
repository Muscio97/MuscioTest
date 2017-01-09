#include <SFML/Graphics.hpp>
#include "cube.hpp"

cube::cube(sf::Vector2f position, sf::Vector2f size) :
	InteractClass(position, size),
	position{ position },
	size{ size }
{
	rectangle.setFillColor(sf::Color(0, 255, 0));
	rectangle.setSize(size);
	rectangle.setPosition(position);
}

void cube::draw(sf::RenderWindow & window) const {
	window.draw(rectangle);
}

void cube::move(sf::Vector2f delta) {
	left += delta.x;
	top += delta.y;
	position += delta;
	rectangle.setPosition(position);

}



