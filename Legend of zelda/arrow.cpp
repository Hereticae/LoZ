#include "arrow.h"


arrow::arrow(sf::Vector2f position, int direction)
{
	fstream entree("fleche.txt");
	_img.loadFromFile("fleche.png");
	_direction = direction;
	if(_direction %2 == 1)
	{
		_position = sf::Vector2f(position.x+((_direction-2)*9), position.y);
		_rectangle = sf::IntRect(_position.x, _position.y, 15 ,5);
		_sprite.setTextureRect(sf::IntRect(0,_direction*15, 15, 5));
	}
	else
	{
		_position = sf::Vector2f(position.x, position.y+((_direction-3)*12));
		_rectangle = sf::IntRect(_position.x, _position.y, 15 ,5);
		_sprite.setTextureRect(sf::IntRect(0,_direction*15, 15, 5));
	}
	//_rect.setPosition
}

arrow::~arrow()
{

}
	
sf::Vector2f arrow::getPosition()
{
	return _position;
}
	
void arrow::move(sf::RenderWindow* window)
{
	window->draw(_sprite);
	window->display();
	//_window->draw(_rect);
}

bool arrow::hit(list<monster> *m, carte*c)
{
	return 1;
}