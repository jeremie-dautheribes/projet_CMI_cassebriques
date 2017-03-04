#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include "../includes/pause.h"

void menuPause (sf::Texture &stop, sf::Sprite &sprite, sf::RenderWindow &window, bool &pause, sf::CircleShape &circle) {

    stop.loadFromFile("images\\Pause.jpg");
    sprite.setTexture(stop);

    circle.move(0,0); // On immobilise la balle
    while (window.isOpen() && pause){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){ //Si une fois la pause lanc�e,nous voulons redemarrer, bouton gauche souris
            pause = false;
            sf::sleep(sf::seconds(0.1f));
        }
        window.clear();
        window.draw(sprite); // On affiche le sprite
        window.display();
    }


    return;
}
