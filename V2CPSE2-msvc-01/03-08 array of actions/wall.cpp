#include <SFML/Graphics.hpp>
#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size):
	InteractClass(position, size),
	position{ position },
	size{ size }
{
	rectangle.setFillColor(sf::Color( 255, 0, 128));
	rectangle.setSize(size);
	rectangle.setPosition(position);
}

void wall::draw(sf::RenderWindow & window) const {
	window.draw(rectangle);
}

void wall::move(sf::Vector2f delta) {
	position += delta;
}

sf::FloatRect wall::getBoundingBox() const {
	sf::FloatRect boundingBox = rectangle.getGlobalBounds();
	return boundingBox;
}



