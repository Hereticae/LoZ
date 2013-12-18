/*******************************************************************
 * Fichier : Map.cpp											   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 16/12/2013                                            *
 * But     :													   *
 *			 													   *
 *******************************************************************/
#include <iostream>

#include "Map.h"
carte::carte()
{
	init();
}

carte::~carte()
{
}



void carte::init()
{
	_vue.setSize(sf::Vector2f (800, 600));
	_vue.zoom(.5);
	_imageWall.loadFromFile("wall.png");
	_textureMap.loadFromFile("map.png");
	_sprite.setTexture(_textureMap);
}

void carte::deplacement(Personnage &perso)
{
	if(!(perso.getPosition().x > ( _vue.getCenter().x - ((_vue.getSize().x/2) - 10))))
	{
		_vue.move(sf::Vector2f(-3,0));
		cout << "Gauche" << endl;
	}
	if(!(perso.getPosition().x < ( _vue.getCenter().x + ((_vue.getSize().x/2) - 26))))
	{
		_vue.move(sf::Vector2f(3,0));
		cout << "Droite" << endl;
	}

	if(!(perso.getPosition().y > ( _vue.getCenter().y - ((_vue.getSize().y/2) - 10))))
	{
		_vue.move(sf::Vector2f(0,-3));
		cout << "Haut" << endl;
	}
	if(!(perso.getPosition().y < ( _vue.getCenter().y + ((_vue.getSize().y/2) - 30))))
	{
		_vue.move(sf::Vector2f(0,3));
		cout << "Bas" << endl;
	}

}

bool carte::collisionMur(const sf::Vector2f &point, int largeur, int hauteur)
{
	bool topLeft = sf::Color (255,0,128) == _imageWall.getPixel(point.x, point.y),
		 topRight = sf::Color (255,0,128) == _imageWall.getPixel(point.x+largeur, point.y),
		 downLeft = sf::Color (255,0,128) == _imageWall.getPixel(point.x, point.y+hauteur),
		 downRight = sf::Color (255,0,128) == _imageWall.getPixel(point.x+largeur, point.y+hauteur);

	return (topLeft || topRight || downLeft || downRight);

}