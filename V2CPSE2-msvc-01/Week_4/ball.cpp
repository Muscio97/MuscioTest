#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include <iostream>


ball::ball( sf::Vector2f position, sf::Vector2f delta, float size ) :
	InteractClass(position, sf::Vector2f(size,size)),
	position{ position },
	delta{ delta },
	size{ size }
{
	circle.setFillColor(sf::Color(0, 255, 255));
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setOrigin((size / 2), (size / 2));
}

sf::Vector2f ball::getPos() const {
	return position;
}

void ball::draw( sf::RenderWindow & window ) const {
	window.draw(circle);
}

void ball::move(){
	left += delta.x;
	top += delta.y;
	position += delta;
	circle.setPosition(position);

}

void ball::interact(InteractClass &object) 
{
	
	if (this != &object) {
		sf::Rect<float> temp;
		if (intersects(object, temp)) {

			if (width / 2 > temp.width)
			{
				delta.x *= -1;
			}	
			if (height / 2 > temp.height)
			{
				delta.y *= -1;
				
			}
			
		
		}

	}
}








