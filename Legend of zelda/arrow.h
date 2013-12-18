#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "arrow.h"

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
	
	item();
public:
	item(int x, int y, int direction);
	~item();
	
	point getPosition();
	
	void move(int direction);
	bool hit(list<monster> m, map m);
};