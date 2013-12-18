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
	_direction = _animCount = _animAtt = _flecheTiree = 0;
	keyUsed1 = keyUsed2 = _attaque = false;
	_rectangle.setFillColor(sf::Color (0,255,255, 153));
	_sword.setFillColor(sf::Color (255,0,0,0));
	arc = NULL;
	Pinit();
}

Personnage::~Personnage()
{
	if(arc!=NULL)
	{
		delete arc;
		arc = NULL;
		if(tiree._arrow!=NULL)
			delete tiree._arrow;
	}
}

void Personnage::deplacement(list<monster> &m, carte &map, sf::RenderWindow *window)
{
	_velocite = sf::Vector2f();
	sf::Vector2f destination = _position;

	if(_attaque == false)
	{
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				destination.x+=2;
				if(!map.collisionMur(destination,17,22))
					bouge( 3, sf::Vector2f(2,0));
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				destination.x-=2;
				if(!map.collisionMur(destination,17,22))
					bouge( 1, sf::Vector2f(-2,0));

			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				destination.y-=2;
				if(!map.collisionMur(destination,17,22))
					bouge( 2, sf::Vector2f(0,-2));
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				destination.y+=2;
				if(!map.collisionMur(destination,17,22))
					bouge( 0, sf::Vector2f(0,2));
			}
			_animCount++;
		}
		else
			keyUsed1 = keyUsed2 = false;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			_attaque = true;
		}

		if(_animCount >= 12)
			_animCount = 0;
		_position += _velocite;
	
		_sprite.setTextureRect(anim[_direction].at(_animCount)._carre);
		_sprite.setTextureRect(anim[_direction].at(_animCount)._carre);

		_sprite.setOrigin(anim[_direction].at(_animCount)._decale);
		_sprite.setPosition(_position);
		
		_rectangle.setPosition(_sprite.getPosition());
		_rectangle.setSize(sf::Vector2f(anim[_direction].at(_animCount)._body.width, anim[_direction].at(_animCount)._body.height));

		_sword.setPosition(sf::Vector2f(0,0));			
		_sword.setSize(sf::Vector2f(0,0));

		

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			tirer(m, map, window);
	}
	else
		attaque();

	window->draw(_sprite);
	window->draw(_sword);
	//window->draw(_rectangle);
	window->display();
}

void Personnage::attaque()
{
	if(_animAtt >= 6)
	{
		_animAtt = 0;
		_attaque = false;
	}
	else
	{
		_sprite.setTextureRect(animAtt[_direction].at(_animAtt)._carre);
		_sprite.setOrigin(animAtt[_direction].at(_animAtt)._decale);
		_sprite.setPosition(_position);

		_rectangle.setPosition(_sprite.getPosition());
		_rectangle.setSize(sf::Vector2f(animAtt[_direction].at(_animAtt)._body.width, animAtt[_direction].at(_animAtt)._body.height));
			
		_sword.setPosition(_sprite.getPosition() + sf::Vector2f(animAtt[_direction].at(_animAtt)._sword.left, animAtt[_direction].at(_animAtt)._sword.top));			
		_sword.setSize(sf::Vector2f(animAtt[_direction].at(_animAtt)._sword.width, animAtt[_direction].at(_animAtt)._sword.height));

		_animAtt++;
	}
}

void Personnage::tirer(list<monster> &m, carte &c, sf::RenderWindow* window)
{
	if(!_flecheTiree)
	{
		tiree._arrow = new arrow(_position, _direction);
		tiree._perso = this;
		tiree._carte = &c;
		tiree._monster = &m;
		tiree._window = window;

		arc = new sf::Thread(moveArrow, tiree);
		arc->launch();
		_flecheTiree = 1;
	}
}

void Personnage::bouge(int pos, sf::Vector2f vecteur)
{
	_direction = pos;
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
			anim[nb].push_back(animation(numero, left, top, width, height, decalex, decaley));
		}
		entree.close();
	}
	
}

void Personnage::lectureAttaque(string nomFichier[])
{
	ifstream entree;
	int numero, left, top, width, height, decalex, decaley, bodyLeft, bodyTop, bodyWidth, bodyHeight, swordLeft, swordTop, swordWidth, swordHeight;
	
	for(int nb = 0; nb < 4; nb++)
	{
		entree.open(nomFichier[nb]);
		while(!entree.eof())
		{
			entree	>> numero >> left >> top >> width >> height >> decalex >> decaley 
					>> bodyLeft >> bodyTop >> bodyWidth >> bodyHeight >> swordLeft 
					>> swordTop >> swordWidth >> swordHeight;
			bodyLeft -= left;
			bodyTop -= top;
			swordLeft -= left + decalex;
			swordTop -= top + decaley;
			animAtt[nb].push_back(animation(numero, sf::IntRect (left, top, width, height) 
				, sf::Vector2f (decalex, decaley), sf::FloatRect(bodyLeft, bodyTop, bodyWidth, bodyHeight)
				, sf::FloatRect (swordLeft, swordTop, swordWidth, swordHeight)));
		}
		entree.close();
	}
	
}

void Personnage::flecheTouche()
{
	_flecheTiree = 0;
}

sf::RectangleShape Personnage::getRect()const
{
	return _rectangle;
}

sf::RectangleShape Personnage::getSword()const
{
	return _sword;
}

void moveArrow(fleche f)
{
	do
	{
		f._arrow->move(f._window);
	}while(!f._arrow->hit(f._monster, f._carte));
	delete f._arrow;
	f._perso->flecheTouche();
}

/*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(_direction == 4)
			_direction = 3;
		else if(_pos2 == 4)
			_pos2 = 3;
		_velocite += sf::Vector2f(3,0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(_direction == 4)
			_direction = 1;
		else if(_pos2 == 4)
			_pos2 = 1;
		_velocite += sf::Vector2f(-3,0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(_direction == 4)
			_direction = 2;
		else if(_pos2 == 4)
			_pos2 = 2;
		_velocite += sf::Vector2f(0,-3);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if(_direction == 4)
			_direction = 0;
		else if(_pos2 == 4)
			_pos2 = 0;
		_velocite += sf::Vector2f(0,3);
		
	}
	if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) 
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		_direction = _pos2 = 4;
		_velocite = sf::Vector2f();

	}*/
