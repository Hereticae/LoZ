/*******************************************************************
 * Fichier : Personnage.cpp										   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 08/10/2013                                            *
 * But     :													   *
 *			 													   *
 *******************************************************************/

#include "Personnage.h"


Personnage::Personnage()
{
	_pos1 = _pos2  = _dep1 = _dep2 = _animCount = _animAtt = 0;
	keyUsed1 = keyUsed2 = attaque = false;
	Pinit();
}

void Personnage::deplacement()
{
	_velocite = sf::Vector2f();
	if(attaque == false)
	{
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
					bouge( 3, sf::Vector2f(3,0));
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				bouge( 1, sf::Vector2f(-3,0));
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				bouge( 2, sf::Vector2f(0,-3));
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				bouge( 0, sf::Vector2f(0,3));
			}
		}
		else
			keyUsed1 = keyUsed2 = false;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			attaque = true;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			_animCount++;
		}
		if(_animCount >= 12)
			_animCount = 0;
		_position += _velocite;
	
		_sprite.setTextureRect(anim[_pos1].at(_animCount)._carre);

		_sprite.setOrigin(anim[_pos1].at(_animCount)._decale);
		_sprite.setPosition(_position);
	}
	else
	{
		if(_animAtt >= 6)
		{
			_animAtt = 0;
			attaque = false;
		}
		else
		{
			_sprite.setTextureRect(animAtt[_pos1].at(_animAtt)._carre);

			_sprite.setOrigin(animAtt[_pos1].at(_animAtt)._decale);
			_sprite.setPosition(_position);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				_animAtt++;
			}
		}
	}
	
}

void Personnage::bouge(int pos, sf::Vector2f vecteur)
{
	_pos1 = pos;
	//_animCount++;
	_velocite += vecteur;

}

void Personnage::Pinit()
{
	string nomFichier[4] = {"Bas.txt", "Gauche.txt", "Haut.txt", "Droite.txt"};
	string attNomFichier[4] = {"AttBas.txt", "AttGauche.txt", "AttHaut.txt", "AttDroite.txt"};
	lectureDeplacement(nomFichier);
	lectureAttaque(attNomFichier);
}

void Personnage::lectureDeplacement(string nomFichier[])
{
	ifstream entree;
	int numero, left, top, width, height, decalex, decaley;
	
	for(int nb = 0; nb < 4; nb++)
	{
		entree.open(nomFichier[nb]);
		while(!entree.eof())
		{
			entree >> numero >> left >> top >> width >> height >> decalex >> decaley;
			anim[nb].push_back(allo(numero, left, top, width, height, decalex, decaley));
		}
		entree.close();
	}
	
}

void Personnage::lectureAttaque(string nomFichier[])
{
	ifstream entree;
	int numero, left, top, width, height, decalex, decaley;
	
	for(int nb = 0; nb < 4; nb++)
	{
		entree.open(nomFichier[nb]);
		while(!entree.eof())
		{
			entree >> numero >> left >> top >> width >> height >> decalex >> decaley;
			animAtt[nb].push_back(allo(numero, left, top, width, height, decalex, decaley));
		}
		entree.close();
	}
	
}



/*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(_pos1 == 4)
			_pos1 = 3;
		else if(_pos2 == 4)
			_pos2 = 3;
		_velocite += sf::Vector2f(3,0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(_pos1 == 4)
			_pos1 = 1;
		else if(_pos2 == 4)
			_pos2 = 1;
		_velocite += sf::Vector2f(-3,0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(_pos1 == 4)
			_pos1 = 2;
		else if(_pos2 == 4)
			_pos2 = 2;
		_velocite += sf::Vector2f(0,-3);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if(_pos1 == 4)
			_pos1 = 0;
		else if(_pos2 == 4)
			_pos2 = 0;
		_velocite += sf::Vector2f(0,3);
		
	}
	if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) 
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		_pos1 = _pos2 = 4;
		_velocite = sf::Vector2f();

	}*/
