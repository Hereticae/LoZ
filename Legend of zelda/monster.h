#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "class.h"
#include "entite.h"
#include "Personnage.h"
#include "Map.h"

using namespace std;


class monster : public Entite
{	
public:
	void look(int direction, const carte &m, const Personnage &j);
	void move(int direction, const carte &m, const Personnage &j);
	int hit(const Personnage &j);
};