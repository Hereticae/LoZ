#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "class.h"
#include "monster.h"
#include "Map.h"
#include <fstream>


////////////////////////////////////////////////
#include <list>
////////////////////////////////////////////////

using namespace std;


class arrow
{
protected:
	sf::Vector2f _position;
	int	_direction;

	sf::IntRect			_rectangle;
	sf::RectangleShape  _rect;
	sf::Image			_img;
	sf::Texture			_texture;
	sf::Sprite			_sprite;
	
	arrow();
public:
	arrow(sf::Vector2f position, int direction);
	~arrow();
	
	sf::Vector2f getPosition();
	
	void move(sf::RenderWindow* window);
	bool hit(list<monster> *m, carte *c);
};