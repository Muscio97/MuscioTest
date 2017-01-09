#include "InteractClass.hpp"

InteractClass::InteractClass(sf::Vector2f position, sf::Vector2f size): 
	Rect(position, size),
	position(position), 
	size(size){}


sf::Vector2f InteractClass::GetPosition() {
	return sf::Vector2f(left, top);
}


sf::Vector2f InteractClass::GetSize() {
	return sf::Vector2f(width, height);
}


