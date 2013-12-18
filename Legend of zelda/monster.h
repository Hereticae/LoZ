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
	monster();
	~monster();
	
	void move(int direction,
		const carte &c,
		const Personnage &j);
};