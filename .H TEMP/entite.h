#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;


class Entite
{
protected:
	struct point
	{
		float x,
			  y;
	};
	
	int _lifeMax,
		_life,
		_direction;
		
	point _coord;
	
public:
	entite();
	entite(int life, int x, int y, int direction);
	~entite();
	void init(int life, int x, int y, int direction);
	
	void setLife(int life);
	void setPosition(int x, int y, int direction);
	
	int getLife();
	point getPosition();
	
	void reduceLife(int dmg);
};
		