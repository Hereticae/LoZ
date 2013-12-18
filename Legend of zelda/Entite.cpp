/*******************************************************************
 * Fichier : Entite.cpp											   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 08/10/2013                                            *
 * But     :													   *
			 													   *
 *******************************************************************/

#include "Entite.h"

void Entite::init(sf::Image img, sf::IntRect rect, sf::Vector2f position)
{
	img.createMaskFromColor(sf::Color(0,128,128));
	_texture.loadFromImage(img);
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(rect);
	_sprite.setScale(1,1);
	_sprite.setPosition(position);
}

void Entite::setEntite(sf::Vector2f position, sf::Vector2f origin, sf::IntRect carree)
{
	_sprite.setPosition(position);
	_sprite.setOrigin(origin);
	_sprite.setTextureRect(carree);
}