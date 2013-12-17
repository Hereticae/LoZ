#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;


class map
{
protected:
	struct point
	{
		float x,
			  y;
	};
			
	vector<point> _walls;
	
public:
	map();
	map(char *name);
	~map();
	void init(char *name);
		
	point getWalls();
};
		