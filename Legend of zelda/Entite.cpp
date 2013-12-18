/*******************************************************************
 * Fichier : Entite.cpp											   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 08/10/2013                                            *
 * But     :													   *
			 													   *
 *******************************************************************/

#include "Entite.h"

Entite::Entite()
{}

Entite::Entite(sf::Image img, sf::IntRect rect, sf::Vector2f position, int life, int direction)
{
	init(img, rect, position, life, direction);
}

void Entite::init(sf::Image img, sf::IntRect rect, sf::Vector2f position, int life, int direction)
{
	img.createMaskFromColor(sf::Color(0,128,128));
	_texture.loadFromImage(img);
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(rect);
	_sprite.setScale(1,1);
	_position = position;
	_maxLife = life;
	_direction = direction;
}

int Entite::getLife()const
{
	return _life;
}

sf::Vector2f Entite::getPosition()const
{
	return _position;
}

sf::Vector2f Entite::getVelocite()const
{
	return _velocite;
}

sf::Image& Entite::getImage()
{
	return _img;
}

sf::Sprite Entite::getSprite()const
{
	return _sprite;
}

void Entite::reduceLife(int dmg)
{
	assert(dmg > 0);

	_life -= dmg;
}