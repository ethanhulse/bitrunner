#include "Header.h"

class Tile {
private:
	sf::Vector2f size;
	sf::Color color;
	bool collides;

public:
	//Constructor
	Tile(sf::Vector2f _size, sf::Color _color, bool _collides) {
		size = _size;
		color = _color;
		collides = _collides;
	}
	//Setters
	void setSize(sf::Vector2f _size) {
		size = _size;
		size = _size;
	}
	void setColor(sf::Color _color) {
		color = _color;
	}
	void setCollides(bool _collides) {
		collides = _collides;
	}
	//Getters
		//Pointer to size array
	sf::Vector2f getSize() {
		return size;
	}
	bool getCollides() {
		return collides;
	}
	sf::Color getColor() {
		return color;
	}
};