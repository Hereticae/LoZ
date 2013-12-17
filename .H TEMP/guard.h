#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "entite.h"
#include "monster.h"
#include "joueur.h"

using namespace std;


class guard : public monster
{
private:
	bool _spoted;

public:
	guard();
	guard(int life, int x, int y, int direction, int dmg);
	~monster();
	
	void look(int direction, const map &m, const joueur &j);
	void move(int direction, const map &m, const joueur &j);
};