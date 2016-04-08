#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>
#include "Menu.h"

void regles (sf::RenderWindow &win) // Fonction pour afficher les règles du jeu
{

    sf::Texture reglejeu; //Créer une texture pour la règle du jeu
    sf::Sprite matteo; //créer un sprite que l'on associera à notre texture
    reglejeu.loadFromFile("images\\regles_jeu.jpg"); // Charger l'image "règles_jeu" que l'on associe à notre texture.
    matteo.setTexture(reglejeu); // association de la texture au sprite
    win.clear();
    win.draw(matteo); // On dessine notre image.
    win.display();
    sf::Event fall; // On crée un evenement nommé "fall"
    bool lecture = true;
    while (lecture){

        while (win.pollEvent(fall)){

            if (fall.type == sf::Event::Closed) // Si on appuie sur la croix, les règles du jeu se ferment.
            {
                return;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Si on appuie sur échap , les règle du jeu se ferment.
            {
                return;
            }

        }

    }



}

void menu(sf::RenderWindow &winwin) // Fonction pour afficher & gérer le menu
{
    sf::Texture texture; //on crée une première texture pour notre image qui servira de bouton commencer
    sf::Texture regle; // on crée une seconde texture pour notre image qui servira de bouton pour lancer les règles du jeu
    sf::Sprite sprite; // On crée un premier sprite pour notre première texture (qui servira à la manipuler)
    sf::Sprite sprite2; // on crée un second sprite pour notre seconde texture
    texture.loadFromFile("images\\start.jpg"); //Charge l'image "commencer"
    regle.loadFromFile("images\\regles.jpg"); // charge l'image "règles"
    sprite.setTexture(texture); // On associe à notre premier sprite notre premiere texture
    sprite2.setTexture(regle); //on associe à notre second sprite notre seconde texture
    sprite.setPosition(sf::Vector2f(300,100)); // On place notre premier bouton à 300 sur l'axe des abscisses et à 100 sur l'axe des y
    sprite2.setPosition(sf::Vector2f(300,300)); // On place notre second bouton à 300 sur l'axe des abscisses et à 300 sur l'axe des y
    sprite.move(sf::Vector2f(10,10));
    sprite2.move(sf::Vector2f(10,10));

    sf::Event Event; // On crée un évènement
    winwin.clear(sf::Color(103,154,198)); //affecte une couleur bleuté en fond de notre menu
    winwin.draw(sprite); // On fait apparaître notre premier bouton en dessinant notre premier sprite
    winwin.draw(sprite2); // On fait apparaître notre deuxième bouton en dessinant notre second sprite
    winwin.display();

    bool finished = false; // On crée un booléen pour laisser notre fenetre de menu ouverte (tant qu'on n'a pas fait d'evenement)
    while (! finished) { // Boucle while pour laisser la fenetre ouverte

        while (winwin.pollEvent(Event)) // Boucle while , qui prend en compte notre fenetre nommée winwin (appelée lors du main) & notre evenement
        {
            if (Event.type == sf::Event::Closed) // Si on appuie sur la croix
            {
                return; // La page se ferme
            }
            if (Event.type == sf::Event::MouseButtonPressed) { // Si on clique sur un bouton de notre souris.
                float X=Event.mouseButton.x; // On récupère les coordonnées de notre souris sur l'axe X
                float Y=Event.mouseButton.y; // On récupère les coordonnées de notre souris sur l'axe Y


                if (Event.mouseButton.button == sf::Mouse::Left && sprite.getGlobalBounds().contains(X, Y)) { // Si on fait un clic gauche et que nos coordonnées de souris coincident avec celle de notre bouton "commencer
                    finished = true; // Notre booléen passe à true et donc on sortira de la boucle while . Donc la page du menu se fermera pour lancer le jeu.

                }
                if (Event.mouseButton.button == sf::Mouse::Left && sprite2.getGlobalBounds().contains(X, Y)){  // Si on fait un clic gauche et que nos coordonnées de souris coincident avec celle de notre bouton "règles"

                    sf::RenderWindow win(sf::VideoMode(1650, 1050), "REGLES DU JEU");// On crée une fenetre pour afficher les règles du jeu
                    regles(win);  // On appelle notre fonction regles qui a pour paramètres notre fenetre créée ci dessus
                    win.close(); // Quand on sort de notre fonction notre fenetre se ferme.
                }
            }
        }

    }
    return;
}


int main (){

    sf::RenderWindow winwin(sf::VideoMode(1000, 800), "MENU"); // On crée notre fenetre qui servira à afficher le menu
    menu(winwin); // on appelle notre fonction menu qui a pour paramètre notre fenetre créée ci dessus
    winwin.close(); // Quand on sort de notre fonction notre fenetre se ferme.

}

