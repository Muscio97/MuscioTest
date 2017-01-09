#include <SFML/Graphics.hpp>
#include "line.hpp"

line::line(sf::Vector2f position, sf::Vector2f size, sf::Color color, float rotation) :
	position{ position },
	size{ size },
	color{ color }
{}

void line::draw(sf::RenderWindow & window) const {
	sf::RectangleShape line;
	line.setFillColor(sf::Color(color));
	line.setSize(size);
	line.setPosition(position);
	line.rotate(rotation);
	window.draw(line);

}
