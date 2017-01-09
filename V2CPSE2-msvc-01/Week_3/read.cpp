#include "read.hpp"




read::read()
{
}

 read_file(std::ifstream & input) {
	sf::Vector2f position;
	std::string name;
	input >> position >> name;

	if (name == "CIRCLE") {
		return std::make_unique<ball>(position,30);
	}
	else if (name == "CUDE") {
		return std::make_unique<cube>(position, sf::Vector2f{ 30.0, 30.0 }, sf::Color(0, 255, 255));

	}
	else if (name == "LINE") {
		return std::make_unique<line>(position, sf);

	}
	else if (name == "") {
		std::cout << "file leeg"
	}

	std::cout << "ken hem niet";
}

