#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "entite.h"
#include "joueur.h"

using namespace std;


class monster : public entite
{
private:
	int _dmg;		
	
public:
	monster();
	monster(int life, int x, int y, int direction, int dmg);
	~monster();
	init(int life, int x, int y, int direction, int dmg);
	
	void move(int direction, const map &m, const joueur &j);
};