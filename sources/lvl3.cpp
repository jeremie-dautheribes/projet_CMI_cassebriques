#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "../includes/lvl.h"
#include "../includes/balle.h"
#include "../includes/briques.h"
#include "../includes/fin.h"
#include "../includes/gagner.h"
#include "../includes/Menu.h"
#include "../includes/pause.h"
#include "../includes/Perdu.h"
#include "../includes/raquette.h"

template<typename T> std::string number_to_string(const T& n) { //Pouvoir faire appara�tre la variable lives en jeu � c�t� de "Lives = "
    std::ostringstream stream;
    stream << n;
    return stream.str();
}

void lvl3(sf:: Text &text,sf::RenderWindow &window, sf::Texture &stop, sf::Sprite &sprite,sf::CircleShape &circle,sf::RectangleShape &rectangle,sf::RectangleShape &Briques, sf::RectangleShape &bord, bool &pause, int** brique, bool &perd, int &niveau){
    float x = 400;
    float y = 300;
    float rectX = 400;
    float vitX = 0.;
    float vitY = 5.;
    int lives = 3;
    int scoreMax = 37;
    text.setString("Lives = " + number_to_string(lives));

    sf::Texture Tbackground3; //On cr�e une texture "Tbackground"
    sf::Sprite Sbackground3; //On cr�e un Sprite "background"
    Tbackground3.loadFromFile("images\\neige.jpg"); // On charge l'image jungle dans la texture
    Sbackground3.setTexture(Tbackground3); //On affecte la texture au sprite
    Sbackground3.setColor(sf::Color(255,255,255,128)); //on lui met de la transparence
    Sbackground3.scale(sf::Vector2f(0.43f,0.65f)); // on change sa taille pour l'adapter � la fenetre
    Sbackground3.setOrigin(sf::Vector2f(12,15)); // on la d�place l�g�rement sur la gauche

    initialisationBrique2(brique,5,16);

    while(window.isOpen() && niveau == 3){

    circle.setPosition(x,y);


    sf::Event event;


        float MouseX = event.mouseMove.x;
        if (pause){ // Si la variable pause est true
            menuPause(stop, sprite, window, pause, circle);

        }

        else {
            if(perd){
                perdu(event,Sbackground3,window,rectangle,bord,circle,Briques,brique,lives,x,y,vitX,vitY,perd,rectX,MouseX,niveau);
                text.setString("Lives = " + number_to_string(lives));
            }
              else{ // Sinon c'est le jeu normal

            circle.move(vitX,vitY);

            x += vitX;
            y += vitY;



            disparitonRebondSurBrique(brique, x, y, vitX, vitY, 5, 3,1,1);
            disparitonRebondSurBrique(brique, x, y, vitX, vitY, 5, 6,1,4);
            disparitonRebondSurBrique(brique, x, y, vitX, vitY, 4, 10,1,7);
            disparitonRebondSurBrique(brique, x, y, vitX, vitY, 5, 14,1,11);




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



        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) // Si le bouton droite est appuy� du clavier , la raquette va � droite
        {
            rectangle.move(10,0);
            rectX += 10;
        }

        if (y > 600){
            perd = true;
            lives--;
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))) // Si le bouton "gauche" du clavier est enfonc� , la raquette va � gauche.
        {
            rectangle.move(-10,0);
            rectX -= 10;
        }

        gagner(window,brique,5,16,niveau,scoreMax);

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                // on met � jour la vue, avec la nouvelle taille de la fen�tre
                sf::FloatRect visibleArea(-250, -50, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));


        }
        }
        window.clear();

        window.draw(Sbackground3);


        creationBrique(window, Briques, brique, 5, 3,1,1);
        creationBrique(window, Briques, brique, 5, 6,1,4);
        creationBrique(window, Briques, brique, 4, 10,1,7);
        creationBrique(window, Briques, brique, 5, 14,1,11);


        window.draw(circle);
        window.draw(rectangle);
        window.draw(text);
        window.draw(bord);
        window.display();
    }
}
