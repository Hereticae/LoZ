/*******************************************************************
 * Fichier : Map.cpp											   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 16/12/2013                                            *
 * But     :													   *
 *			 													   *
 *******************************************************************/


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
}

//void carte::deplacement(Personnage &perso)
//{
//	if(perso._position.x < _vue.getCenter().x)
//	{
//		_vue.move(sf::Vector2f(3,0));
//		perso._velocite += sf::Vector2f(3,0);
//	}
//	if(perso._position.x < 790)
//	{
//		_vue.move(sf::Vector2f(-3,0));
//		perso._velocite += sf::Vector2f(-3,0);
//	}
//
//	if(perso._position.y < 10)
//	{
//		_vue.move(sf::Vector2f(0,3));
//		perso._velocite += sf::Vector2f(0,3);
//	}if(perso._position.y < 590)
//	{
//		_vue.move(sf::Vector2f(0,-3));
//		perso._velocite += sf::Vector2f(0,-3);
//	}
//
//}