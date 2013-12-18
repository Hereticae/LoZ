#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "class.h"
#include "monster.h"
#include "Map.h"


////////////////////////////////////////////////
#include <list>
////////////////////////////////////////////////

using namespace std;


class arrow
{
protected:
	struct point
	{
		float x,
			  y;
	};

	int	_direction;
		
	point _coord;
	
	arrow();
public:
	arrow(int x, int y, int direction);
	~arrow();
	
	point getPosition();
	
	void move(int direction);
	bool hit(list<monster> m, carte c);
};