/*******************************************************************
 * Fichier : Legend of zelda.cpp											   *
 * Auteur  : Maxime Fontaine Bombardier                            *
 * Date    : 19/11/2013                                            *
 * But     :													   *
			 													   *
 *******************************************************************/
#pragma once
#include "class.h"
#include "Map.h"

using namespace std;

int main()
{
	Personnage Link;
	// Create the main window
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 600), "Legend of Zelda");
	
	window->setFramerateLimit(60);
    // Load a sprite to display
	sf::Image map;
	sf::Texture textMap;
	sf::Sprite spriteMap;
	if (!map.loadFromFile("map.png"))
        return EXIT_FAILURE;
	textMap.loadFromImage(map);
	spriteMap.setTexture(textMap);
	spriteMap.setScale(1,1);
    if (!Link.getImage().loadFromFile("Link necessaire.png"))
        return EXIT_FAILURE;
	Link.init(Link.getImage(), sf::IntRect(101,127,15,24), sf::Vector2f(250,250), 5,0);

	sf::RectangleShape rectangle;
	
	carte vue;
	
	//texture.loadFromImage(img);
	//Link._sprite.setTexture(texture);
	//Link._sprite.setTextureRect(sf::IntRect(1,119,15,27));
	//Link._sprite.setScale(2,2);
	//Link._sprite.set
    // Start the game loop
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window->close();
        }
		Link.deplacement();
		vue.deplacement(Link);
		vue.collisionMur(Link);
        // Clear screen
        window->clear();
		window->setView(vue._vue);
		window->draw(vue._sprite);
        // Draw the sprite

        window->draw(Link.getSprite());
		window->draw(Link.getRect());
		window->draw(Link.getSword());

        // Update the window
        window->display();
    }
	delete window;
    return EXIT_SUCCESS;
}