#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>
#include "Perdu.h"
#include "raquette.h"
#include "briques.h"


void menuperdu (sf::RenderWindow &fenetre){ // On cr�e une fonction "menuperdu" pour lancer une fen�tre avec des boutons recommencer & quitter lorsque l'on a perdu

    sf::Font fontp; // on initialise un fond
    sf::Text textp; // on initialise un texte
    fontp.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'�crire (ici �criture basique)
    textp.setFont(fontp); //On affecte au texte , un fond
    textp.setString("Vous avez perdu , voulez vous recommencer?"); // Le texte vaut "vous avez gagn�" (ce qui sera affich� plus tard)
    textp.setCharacterSize(30); // Change la taille de la police � 30
    textp.setStyle(sf::Text::Regular); // Pas d'effet d'�criture : on a une police en "regular"

    //Pour centrer le texte:
    sf::FloatRect textRectperdu = textp.getLocalBounds();
    textp.setOrigin(textRectperdu.width/2,textRectperdu.height/2);
    textp.setPosition(sf::Vector2f(500,100));

    sf::Texture restart; // On cr�e une premi�re texture pour notre bouton "recommencer"
    sf::Texture leave; // on cr�e une seconde texture pour notre bouton "quitter"
    sf::Sprite rejouer; // On cr�e notre premier sprite pour notre bouton "recommencer" que l'on associera � notre texture "restart"
    sf::Sprite verlassen; // On cr�e notre second sprite pour notre bouton "quitter" que l'on associera � notre texture "leave"
    restart.loadFromFile("images\\recommencer.jpg"); //Charge l'image "recommencer"
    leave.loadFromFile("images\\quitter.jpg"); //charge l'image "quitter"
    rejouer.setTexture(restart); // On associe notre premi�re texture nomm�e "restart" � notre premier sprite "rejouer"
    verlassen.setTexture(leave);// On associe notre seconde texture nomm�e "leave" � notre second sprite "verlassen"
    rejouer.setPosition(sf::Vector2f(240,200)); // On associe � notre bouton "rejouer" une position � 240 pixel sur notre axe X & � 100 sur notre axe Y
    verlassen.setPosition(sf::Vector2f(300,400)); // On associe � notre bouton "quitter" une position � 300 pixel sur notre axe X & � 300 sur notre axe Y
    rejouer.move(sf::Vector2f(10,10));
    verlassen.move(sf::Vector2f(10,10));

    sf::Event evenement; // On cr�e un evenement
    fenetre.clear(sf::Color(103,154,198)); //affecte une couleur bleut� en fond de notre menu
    fenetre.draw(textp);
    fenetre.draw(rejouer); // On dessine notre sprite "rejouer" pour afficher notre bouton "recommencer"
    fenetre.draw(verlassen); // On dessine notre sprite "verlassen" pour afficher notre bouton "quitter"
    fenetre.display();

    bool pourfinir = false; // On cr�e un bool�en pour laisser notre fenetre de menu ouverte (tant qu'on n'a pas fait d'evenement)
    while (! pourfinir) { // Boucle while pour laisser la fenetre ouverte

        while (fenetre.pollEvent(evenement)) // Boucle while , qui prend en compte notre fenetre nomm�e winwin (appel�e lors du main) & notre evenement
        {

            if (evenement.type == sf::Event::Closed) // Si on appuie sur la croix
            {
                return; //la page se ferme
            }
            if (evenement.type == sf::Event::MouseButtonPressed) { // Si on clique sur un bouton de notre souris.
                float X=evenement.mouseButton.x; // On r�cup�re les coordonn�es de notre souris sur l'axe X
                float Y=evenement.mouseButton.y; // On r�cup�re les coordonn�es de notre souris sur l'axe Y


                if (evenement.mouseButton.button == sf::Mouse::Left && verlassen.getGlobalBounds().contains(X, Y)) { // Si on fait un clic gauche et que les coordonn�es de notre souris coincident avec notre sprite "verlassen"

                    return; // La page se ferme et donc on quitte le jeu

                }
                if (evenement.mouseButton.button == sf::Mouse::Left && rejouer.getGlobalBounds().contains(X, Y)){ // Si on fait un clic gauche et que les coordon�es de notre souris coincident avec notre sprite "rejour"

                        pourfinir = true; // La fenetre "Perdu" se ferme et le jeu se relance

                }
            }
        }

    }
    return;
}

void perdu (sf::Event &event, sf::RenderWindow &window, sf::RectangleShape &rectangle, sf::CircleShape &circle, sf::RectangleShape &Briques, int** brique, int &lives, float &xBalle, float &yBalle, float &vitX, float &vitY, bool &perd, float &rectX){
    xBalle = 400;
    yBalle = 500;
    circle.setPosition(xBalle,yBalle);

    if (lives == 0)
    {
        circle.move(0,0);
        sf::RenderWindow perdu(sf::VideoMode(1000, 800), "PERDU");
        menuperdu(perdu);
        perdu.close();
        lives = 3;
    }

    while (window.isOpen() && perd){


        circle.move(0,0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && (lives != 0)){
            perd = false;
            vitX = 0;
            sf::sleep(sf::seconds(0.1f));
        }

        raquetteSouris(event,rectangle,rectX);

        window.clear(sf::Color::Blue);
        creationBrique(window, Briques, brique, 4, 14);
        window.draw(circle);
        window.draw(rectangle);
        window.display();
    }

}


/*int main (){

    sf::RenderWindow wiwi(sf::VideoMode(1000, 800), "PERDU");
    int lives =0;
    losen(lives, wiwi);
    wiwi.close();
}*/

