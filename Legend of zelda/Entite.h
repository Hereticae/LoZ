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

using namespace std;


class Entite
{
	public:
	sf::Vector2f	_velocite,
					_position;
	sf::IntRect		_rectangle;
	sf::Image		_img;
	sf::Texture		_texture;
	sf::Sprite		_sprite;

	void init(sf::Image img, sf::IntRect, sf::Vector2f);
	void setEntite(sf::Vector2f Position, sf::Vector2f origin, sf::IntRect carree);


};