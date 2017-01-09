#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball(sf::Vector2f position, float size, sf::Color color) :
	position{ position },
	size{ size },
	color{ color }
{}

void ball::draw( sf::RenderWindow & window ) const {
	sf::CircleShape circle;
	circle.setFillColor(sf::Color(color));
	circle.setRadius(size);
	circle.setPosition(position);
	window.draw(circle);
}


void ball::jump( sf::Vector2f target ){
	position = target;
}

void ball::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}
