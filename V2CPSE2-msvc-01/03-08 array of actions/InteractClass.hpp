
#ifndef InteractClass_HPP
#define InteractClass_HPP

#include <SFML/Graphics.hpp>

class InteractClass : public sf::Rect<float>
{
private:
	sf::Vector2f position;
	sf::Vector2f size;
public:
	InteractClass(sf::Vector2f position, sf::Vector2f size);

	virtual void draw(sf::RenderWindow & window) const = 0;

	virtual void interact(InteractClass &object){};

	sf::Vector2f GetPosition();

	sf::Vector2f GetSize();

	

};

#endif









