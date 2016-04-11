#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
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

void lvl1(sf:: Text &text,sf::RenderWindow &window, sf::Texture &stop, sf::Sprite &sprite,sf::CircleShape &circle,sf::RectangleShape &rectangle,sf::RectangleShape &Briques, sf::RectangleShape &bord, bool &pause, int** brique, bool &perd,int &niveau){

    float x = 400;
    float y = 300;
    float rectX = 400;
    float vitX = 0.;
    float vitY = 5.;
    int lives = 3;

    sf::Texture Tbackground1; //On crée une texture "Tbackground"
    sf::Sprite Sbackground1; //On crée un Sprite "background"
    Tbackground1.loadFromFile("images\\jungle.jpg"); // On charge l'image jungle dans la texture
    Sbackground1.setTexture(Tbackground1); //On affecte la texture au sprite
    Sbackground1.setColor(sf::Color(255,255,255,128)); //on lui met de la transparence
    Sbackground1.scale(sf::Vector2f(0.75f,0.95f)); // on change sa taille pour l'adapter à la fenetre
    Sbackground1.setOrigin(sf::Vector2f(-1,1)); // on la déplace légèrement sur la gauche

    while(window.isOpen() && niveau == 1){
        circle.setPosition(x,y);


        sf::Event event;


        float MouseX = event.mouseMove.x;
        if (pause){ // Si la variable pause est true
            menuPause(stop, sprite, window, pause, circle);

        }

        else {
            if(perd){
                perdu(event,Sbackground1,window,rectangle,bord,circle,Briques,brique,lives,x,y,vitX,vitY,perd,rectX,MouseX,4,14);
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

        gagner(window,brique,4,14,niveau);

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
        window.clear();

        window.draw(Sbackground1);


        creationBrique(window, Briques, brique, 4, 14);

        window.draw(circle);
        window.draw(rectangle);
        window.draw(text);
        window.draw(bord);
        window.display();
        }
    }
