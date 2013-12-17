#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "entite.h"

using namespace std;


class joueur : public entite
{
private:
	int _dmg;		
	
public:
	joueur();
	joueur(int dmg);
	~joueur();
	init(int dmg;
	
	shoot(int direction, list<monster> &m, const vector<point> &p);
	attack(int direction, list<monster> &m);
	void move(int direction, const vector<point> &p);
};