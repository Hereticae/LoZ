#include "arrow.h"

arrow::arrow(sf::Vector2f position, int direction)
{
	_position = position;
	_direction = direction;
}

arrow::~arrow()
{

}
	
sf::Vector2f arrow::getPosition()
{
	return _position;
}
	
void arrow::move()
{

}

bool arrow::hit(list<monster> *m, carte*c)
{
	return 1;
}