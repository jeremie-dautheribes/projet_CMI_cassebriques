#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include "lvl.h"
#include "Menu.h"
#include "briques.h"
#include "fin.h"


template<typename T> std::string number_to_string(const T& n) { //Pouvoir faire apparaître la variable lives en jeu à côté de "Lives = "
    std::ostringstream stream;
    stream << n;
    return stream.str();
}

int main()
{
    sf::SoundBuffer jungle;
    sf::Sound Sjungle;
    jungle.loadFromFile("sons\\rythme.ogg");
    Sjungle.setBuffer(jungle);
    Sjungle.play();
    Sjungle.setLoop(true);

    int lives = 3;
    bool perd =  false;
    sf::RenderWindow winwin(sf::VideoMode(800, 600), "MENU");
    menu(winwin);
    winwin.close();
    sf:: Font font;
    sf:: Text text;
    font.loadFromFile("Fonts\\introrustg-base2line.otf");
    text.setFont(font);
    text.setString("Lives = " + number_to_string(lives));
    text.setCharacterSize(24);
    text.setColor(sf::Color::Black);

    sf::Texture stop; // Texture de l'image
    stop.loadFromFile("images\\Pause.jpg");
    sf::Sprite sprite;
    sprite.setTexture(stop); // On associe la texture à un sprite

    bool pause = false;
    int niveau = 1;

    sf::RectangleShape bord;
    bord.setSize(sf::Vector2f(820,685));
    bord.setFillColor(sf::Color::Transparent);
    bord.setOutlineThickness(10);

    sf::RenderWindow window(sf::VideoMode(800, 600), "CasseBriques"); //initialise la fenetre
    sf::CircleShape circle(5.f); //Créer notre balle : un cercle de dimension 8
    sf::RectangleShape rectangle; //créer notre raquette : un rectangle
    sf::RectangleShape Briques;
    rectangle.setSize(sf::Vector2f(115,15)); //Taille de notre raquette
    rectangle.setFillColor(sf::Color::Cyan); //Couleur de notre raquette
    rectangle.setPosition(400,550); // position initiale de notre raquette
    //circle.setPosition(x,y);
    circle.setFillColor(sf::Color::Transparent); //Couleur de notre balle
    circle.setOutlineThickness(5);
    sprite.setPosition(200.f, 100.f); // Position du Sprite Pause


    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);


    sf::Image icon;
    icon.loadFromFile("images\\cochone.jpg");
    window.setIcon(125,125, icon.getPixelsPtr());




    window.setMouseCursorVisible(false);

    int** brique= new int*[5];
    for(int k(0); k < 5; k++)
        brique[k]= new int[16];

    initialisationBrique(brique, 5, 16);

while(window.isOpen()){


        lvl1(text,window,stop,sprite,circle,rectangle,Briques,bord,pause,brique,perd,niveau);
        lvl2(text,window,stop,sprite,circle,rectangle,Briques,bord,pause,brique,perd,niveau);
        lvl3(text,window,stop,sprite,circle,rectangle,Briques,bord,pause,brique,perd,niveau);



}

    for(int k(0); k<5; k++)
        delete[] brique[k];
    delete [] brique;
    return 0;
}
