#include "triangle.hpp"

#include <SFML/Graphics.hpp>



triangle::triangle(sf::Vector2f position, float size, sf::Color color):
	position{ position },
	size{ size },
	color{ color }
{}

void triangle::draw(sf::RenderWindow & window) const {
	sf::CircleShape triangle(size, 3);
	triangle.setFillColor(sf::Color(color));
	triangle.setPosition(position);
	window.draw(triangle);
}


void triangle::jump(sf::Vector2f target) {
	position = target;
}

void triangle::jump(sf::Vector2i target) {
	jump(sf::Vector2f(
		static_cast< float >(target.x),
		static_cast< float >(target.y)
	));
}
