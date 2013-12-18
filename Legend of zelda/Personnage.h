/*******************************************************************
 * Fichier : Personnage.h										   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 08/10/2013                                            *
 * But     :													   *
			 													   *
 *******************************************************************/

#pragma once
#include "class.h"
#include "Entite.h"
#include "monster.h"
#include <vector>
#include <fstream>

using namespace std;

struct animation
{
	int _nb;
	sf::IntRect _carre;
	sf::Vector2f _decale;
	sf::FloatRect _body,
				_sword;
	animation(int nb, int left, int top, int width, int height, int decalex, int decaley)
	{
		_nb = nb;
		
		_decale = sf::Vector2f(decalex, decaley);
		
		_carre = sf::IntRect(left, top, width, height);
		_body = sf::FloatRect(left, top, width, height);
		_sword = sf::FloatRect(0, 0, 0, 0);
	}

	animation(int nb, sf::IntRect carre, sf::Vector2f decale, sf::FloatRect body, sf::FloatRect sword = sf::FloatRect (0,0,0,0))
	{
		_nb = nb;
		_carre = carre;
		_decale = decale;
		_body = body;
		_sword = sword;
	}
};


class Personnage : public Entite
{
protected:
	int _animCount,
		_animAtt;

	bool	keyUsed1,
			keyUsed2,
			_attaque,
			_flecheTiree;

	vector<animation> anim[4],
				 animAtt[4];

	sf::RectangleShape	_rectangle,
						_sword;

	//sf::Thread arc;

public:
	Personnage();

	void deplacement();
	void attaque();
	void tirer();
	void bouge(int pos, sf::Vector2f vecteur);

	void Pinit();
	void lectureDeplacement(string nomFichier[]);
	void lectureAttaque(string nomFichier[]);

	sf::RectangleShape getRect()const;
	sf::RectangleShape getSword()const;
	//get



};