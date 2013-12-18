/*******************************************************************
 * Fichier : Map.h												   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 16/12/2013                                            *
 * But     :													   *
 *			 													   *
 *******************************************************************/

#pragma once
#include "class.h"
#include "Personnage.h"

using namespace std;

class carte
{
private:
	
	

public:
	carte();
	~carte();
	sf::View _vue;
	sf::Texture _textureMap;

	sf::Image	_imageWall;

	sf::Sprite	_sprite;
	void init();
	
	void deplacement(Personnage &perso);
	bool collisionMur(const sf::Vector2f &point, int largeur, int hauteur);






};