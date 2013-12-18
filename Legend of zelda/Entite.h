/*******************************************************************
 * Fichier : Entite.h											   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 08/10/2013                                            *
 * But     :													   *
			 													   *
 *******************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <assert.h>
#include "class.h"

using namespace std;


class Entite
{
protected:
	sf::Vector2f	_velocite,
					_position;
	sf::IntRect		_rectangle;
	sf::Image		_img;
	sf::Texture		_texture;
	sf::Sprite		_sprite;

	int _maxLife,
		_life,
		_direction;

public:
	Entite();
	Entite(sf::Image img, sf::IntRect rect, sf::Vector2f position, int life, int direction);
	void init(sf::Image img, sf::IntRect rect, sf::Vector2f position, int life, int direction);

	int getLife()const;
	sf::Vector2f getPosition()const;
	sf::Vector2f getVelocite()const;

	sf::Image& getImage();
	sf::Sprite getSprite()const;

	void reduceLife(int dmg);
};