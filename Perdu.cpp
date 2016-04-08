#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>
#include "Perdu.h"

void menuperdu (sf::RenderWindow &fenetre){ // On crée une fonction "menuperdu" pour lancer une fenètre avec des boutons recommencer & quitter lorsque l'on a perdu

    sf::Texture restart; // On crée une première texture pour notre bouton "recommencer"
    sf::Texture leave; // on crée une seconde texture pour notre bouton "quitter"
    sf::Sprite rejouer; // On crée notre premier sprite pour notre bouton "recommencer" que l'on associera à notre texture "restart"
    sf::Sprite verlassen; // On crée notre second sprite pour notre bouton "quitter" que l'on associera à notre texture "leave"
    restart.loadFromFile("recommencer.jpg"); //Charge l'image "recommencer"
    leave.loadFromFile("quitter.jpg"); //charge l'image "quitter"
    rejouer.setTexture(restart); // On associe notre première texture nommée "restart" à notre premier sprite "rejouer"
    verlassen.setTexture(leave);// On associe notre seconde texture nommée "leave" à notre second sprite "verlassen"
    rejouer.setPosition(sf::Vector2f(240,100)); // On associe à notre bouton "rejouer" une position à 240 pixel sur notre axe X & à 100 sur notre axe Y
    verlassen.setPosition(sf::Vector2f(300,300)); // On associe à notre bouton "quitter" une position à 300 pixel sur notre axe X & à 300 sur notre axe Y
    rejouer.move(sf::Vector2f(10,10));
    verlassen.move(sf::Vector2f(10,10));

    sf::Event evenement; // On crée un evenement
    fenetre.clear(sf::Color(103,154,198)); //affecte une couleur bleuté en fond de notre menu
    fenetre.draw(rejouer); // On dessine notre sprite "rejouer" pour afficher notre bouton "recommencer"
    fenetre.draw(verlassen); // On dessine notre sprite "verlassen" pour afficher notre bouton "quitter"
    fenetre.display();

    bool pourfinir = false; // On crée un booléen pour laisser notre fenetre de menu ouverte (tant qu'on n'a pas fait d'evenement)
    while (! pourfinir) { // Boucle while pour laisser la fenetre ouverte

        while (fenetre.pollEvent(evenement)) // Boucle while , qui prend en compte notre fenetre nommée winwin (appelée lors du main) & notre evenement
        {

            if (evenement.type == sf::Event::Closed) // Si on appuie sur la croix
            {
                return; //la page se ferme
            }
            if (evenement.type == sf::Event::MouseButtonPressed) { // Si on clique sur un bouton de notre souris.
                float X=evenement.mouseButton.x; // On récupère les coordonnées de notre souris sur l'axe X
                float Y=evenement.mouseButton.y; // On récupère les coordonnées de notre souris sur l'axe Y


                if (evenement.mouseButton.button == sf::Mouse::Left && verlassen.getGlobalBounds().contains(X, Y)) { // Si on fait un clic gauche et que les coordonnées de notre souris coincident avec notre sprite "verlassen"

                    return; // La page se ferme et donc on quitte le jeu

                }
                if (evenement.mouseButton.button == sf::Mouse::Left && rejouer.getGlobalBounds().contains(X, Y)){ // Si on fait un clic gauche et que les coordonées de notre souris coincident avec notre sprite "rejour"

                        pourfinir = true; // La fenetre "Perdu" se ferme et le jeu se relance

                }
            }
        }

    }
    return;
}


/*int main (){

    sf::RenderWindow fenetre(sf::VideoMode(1000, 800), "PERDU");
    menuperdu(fenetre);
    fenetre.close();

}
*/
