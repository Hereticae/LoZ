/*******************************************************************
 * Fichier : Personnage.h										   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 08/10/2013                                            *
 * But     :													   *
			 													   *
 *******************************************************************/

#pragma once
#include "Entite.h"
#include <vector>
#include <fstream>

using namespace std;

struct allo
{
	int _nb;
	sf::IntRect _carre;
	sf::Vector2f _decale;
	allo(int nb, int left, int top, int width, int height, int decalex, int decaley)
	{
		_nb = nb;
		_carre = sf::IntRect(left, top, width, height);
		_decale = sf::Vector2f(decalex, decaley);
	}

	allo(int nb, sf::IntRect carre, sf::Vector2f decale)
	{
		_nb = nb;
		_carre = carre;
		_decale = decale;
	}
};


class Personnage : public Entite
{
	public:
	int _pos1,
		_pos2,
		_dep1,
		_dep2,
		_animCount,
		_animAtt;
	bool	keyUsed1,
			keyUsed2,
			attaque;
	vector<allo> anim[4],
				 animAtt[4];
	Personnage();

	void deplacement();
	void bouge(int pos, sf::Vector2f vecteur);

	void Pinit();
	void lectureDeplacement(string nomFichier[]);
	void lectureAttaque(string nomFichier[]);
	//get



};