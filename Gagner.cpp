#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>
#include "gagner.h"

void menugagner (sf::RenderWindow &gagner){ // On crée une fonction "menuGagner" pour lancer une fenètre avec des boutons niveau suivant & quitter lorsque l'on a gagné


    sf::Texture level; // On crée une première texture pour notre bouton "Niveau_Suivant"
    sf::Texture fara; // on crée une seconde texture pour notre bouton "quitter"
    sf::Sprite niveausuiv; // On crée notre premier sprite pour notre bouton "niveau Suivant" que l'on associera à notre texture "restart"
    sf::Sprite lasciare; // On crée notre second sprite pour notre bouton "quitter" que l'on associera à notre texture "leave"
    level.loadFromFile("images\\niveau_suivant.jpg"); //Charge l'image "Niveau Suivant"
    fara.loadFromFile("images\\quitter.jpg"); //charge l'image "quitter"
    niveausuiv.setTexture(level); // On associe notre première texture nommée "level" à notre premier sprite "niveausuiv"
    lasciare.setTexture(fara);// On associe notre seconde texture nommée "fara" à notre second sprite "lasciare"
    niveausuiv.setPosition(sf::Vector2f(240,100)); // On associe à notre bouton "Niveau_Suivant" une position à 240 pixel sur notre axe X & à 100 sur notre axe Y
    lasciare.setPosition(sf::Vector2f(300,300)); // On associe à notre bouton "quitter" une position à 300 pixel sur notre axe X & à 300 sur notre axe Y
    niveausuiv.move(sf::Vector2f(10,10));
    lasciare.move(sf::Vector2f(10,10));

    sf::Event evento; // On crée un evenement
    gagner.clear(sf::Color(103,154,198)); //affecte une couleur bleuté en fond de notre menu
    gagner.draw(niveausuiv); // On dessine notre sprite "niveauSuiv" pour afficher notre bouton "recommencer"
    gagner.draw(lasciare); // On dessine notre sprite "lasciare" pour afficher notre bouton "quitter"
    gagner.display();

    bool enda = false; // On crée un booléen pour laisser notre fenetre de menu ouverte (tant qu'on n'a pas fait d'evenement)
    while (! enda) { // Boucle while pour laisser la fenetre ouverte

        while (gagner.pollEvent(evento)) // Boucle while , qui prend en compte notre fenetre nommée winwin (appelée lors du main) & notre evenement
        {

            if (evento.type == sf::Event::Closed) // Si on appuie sur la croix
            {
                return; //la page se ferme
            }
            if (evento.type == sf::Event::MouseButtonPressed) { // Si on clique sur un bouton de notre souris.
                float X=evento.mouseButton.x; // On récupère les coordonnées de notre souris sur l'axe X
                float Y=evento.mouseButton.y; // On récupère les coordonnées de notre souris sur l'axe Y


                if (evento.mouseButton.button == sf::Mouse::Left && niveausuiv.getGlobalBounds().contains(X, Y)) { // Si on fait un clic gauche et que les coordonnées de notre souris coincident avec notre sprite "verlassen"

                    return; // La page se ferme et donc on quitte le jeu

                }
                if (evento.mouseButton.button == sf::Mouse::Left && lasciare.getGlobalBounds().contains(X, Y)){ // Si on fait un clic gauche et que les coordonées de notre souris coincident avec notre sprite "rejour"

                        enda = true; // La fenetre "Perdu" se ferme et le jeu se relance

                }
            }
        }

    }
    return;
}

/*int main (){

    sf::RenderWindow gagner(sf::VideoMode(1000, 800), "GAGNE");
    menugagner(gagner);
    gagner.close();

}*/

