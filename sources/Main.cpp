#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include "balle.h"
#include "briques.h"
#include "fin.h"
#include "gagner.h"
#include "Menu.h"
#include "pause.h"
#include "Perdu.h"
#include "raquette.h"

template<typename T> std::string number_to_string(const T& n) { //Pouvoir faire apparaître la variable lives en jeu à côté de "Lives = "
    std::ostringstream stream;
    stream << n;
    return stream.str();
}

int main()
{
    sf::SoundBuffer jungle; // on créé un sound Buffer
    sf::Sound Sjungle; // on créé un son
    jungle.loadFromFile("songs\\rythme.ogg");
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

    float x = 400;
    float y = 300;
    float rectX = 400;
    float vitX = 0.;
    float vitY = 5.;
    bool pause = false;

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
    circle.setPosition(x,y);
    circle.setFillColor(sf::Color::Transparent); //Couleur de notre balle
    circle.setOutlineThickness(5);
    sprite.setPosition(200.f, 100.f); // Position du Sprite Pause


    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);







    window.setMouseCursorVisible(false);

    int** brique= new int*[5];
    for(int k(0); k < 5; k++)
        brique[k]= new int[16];

    initialisationBrique(brique, 5, 16);

    while (window.isOpen())
    {

        sf::Event event;


        float MouseX = event.mouseMove.x;
        if (pause){ // Si la variable pause est true
            menuPause(stop, sprite, window, pause, circle);

        }

        else {
            if(perd){
                perdu(event,window,rectangle,bord,circle,Briques,brique,lives,x,y,vitX,vitY,perd,rectX,MouseX);
                text.setString("Lives = " + number_to_string(lives));
            }
              else{ // Sinon c'est le jeu normal

            circle.move(vitX,vitY);

            x += vitX;
            y += vitY;



            disparitonRebondSurBrique(brique, x, y, vitX, vitY, 4, 14);


            raquetteSouris(event,rectangle,rectX);


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }

         rebond(x, y, MouseX ,vitX ,vitY ,rectX);

        }
        }






        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){ //Condition pour lancer l'algorithme de la pause
            pause = true;
            sf::sleep(sf::seconds(0.1f));
        }



        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) // Si le bouton droite est appuyé du clavier , la raquette va à droite
        {
            rectangle.move(10,0);
            rectX += 10;
        }

        if (y > 600){
            perd = true;
            lives--;
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))) // Si le bouton "gauche" du clavier est enfoncé , la raquette va à gauche.
        {
            rectangle.move(-10,0);
            rectX -= 10;
        }

        gagner(window,brique,4,14);

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                // on met à jour la vue, avec la nouvelle taille de la fenêtre
                sf::FloatRect visibleArea(-250, -50, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));


        }
        }
        window.clear(sf::Color::Blue);


        creationBrique(window, Briques, brique, 4, 14);

        window.draw(circle);
        window.draw(rectangle);
        window.draw(text);
        window.draw(bord);
        window.display();

    }

    delete [] brique;
    return 0;
}
