#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>
#include "../includes/Menu.h"

void regles (sf::RenderWindow &win) // Fonction pour afficher les r�gles du jeu
{

    sf::Texture reglejeu; //Cr�er une texture pour la r�gle du jeu
    sf::Sprite matteo; //cr�er un sprite que l'on associera � notre texture
    reglejeu.loadFromFile("images\\regles_jeu.jpg"); // Charger l'image "r�gles_jeu" que l'on associe � notre texture.
    matteo.setTexture(reglejeu); // association de la texture au sprite
    win.clear();
    win.draw(matteo); // On dessine notre image.
    win.display();
    sf::Event fall; // On cr�e un evenement nomm� "fall"
    bool lecture = true;
    while (lecture){

        while (win.pollEvent(fall)){

            if (fall.type == sf::Event::Closed) // Si on appuie sur la croix, les r�gles du jeu se ferment.
            {
                lecture = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Si on appuie sur �chap , les r�gle du jeu se ferment.
            {
                lecture = false;
            }

        }

    }



}

void menu(sf::RenderWindow &winwin) // Fonction pour afficher & g�rer le menu
{
    sf::Texture texture; //on cr�e une premi�re texture pour notre image qui servira de bouton commencer
    sf::Texture regle; // on cr�e une seconde texture pour notre image qui servira de bouton pour lancer les r�gles du jeu
    sf::Sprite sprite; // On cr�e un premier sprite pour notre premi�re texture (qui servira � la manipuler)
    sf::Sprite sprite2; // on cr�e un second sprite pour notre seconde texture
    texture.loadFromFile("images\\start.jpg"); //Charge l'image "commencer"
    regle.loadFromFile("images\\regles.jpg"); // charge l'image "r�gles"
    sprite.setTexture(texture); // On associe � notre premier sprite notre premiere texture
    sprite2.setTexture(regle); //on associe � notre second sprite notre seconde texture
    sprite.setPosition(sf::Vector2f(300,100)); // On place notre premier bouton � 300 sur l'axe des abscisses et � 100 sur l'axe des y
    sprite2.setPosition(sf::Vector2f(300,300)); // On place notre second bouton � 300 sur l'axe des abscisses et � 300 sur l'axe des y
    sprite.move(sf::Vector2f(10,10));
    sprite2.move(sf::Vector2f(10,10));

    sf::Event Event; // On cr�e un �v�nement
    winwin.clear(sf::Color(103,154,198)); //affecte une couleur bleut� en fond de notre menu
    winwin.draw(sprite); // On fait appara�tre notre premier bouton en dessinant notre premier sprite
    winwin.draw(sprite2); // On fait appara�tre notre deuxi�me bouton en dessinant notre second sprite
    winwin.display();

    bool finished = false; // On cr�e un bool�en pour laisser notre fenetre de menu ouverte (tant qu'on n'a pas fait d'evenement)
    while (! finished) { // Boucle while pour laisser la fenetre ouverte

        while (winwin.pollEvent(Event)) // Boucle while , qui prend en compte notre fenetre nomm�e winwin (appel�e lors du main) & notre evenement
        {
            if (Event.type == sf::Event::Closed) // Si on appuie sur la croix
            {
                return; // La page se ferme
            }
            if (Event.type == sf::Event::MouseButtonPressed) { // Si on clique sur un bouton de notre souris.
                float X=Event.mouseButton.x; // On r�cup�re les coordonn�es de notre souris sur l'axe X
                float Y=Event.mouseButton.y; // On r�cup�re les coordonn�es de notre souris sur l'axe Y


                if (Event.mouseButton.button == sf::Mouse::Left && sprite.getGlobalBounds().contains(X, Y)) { // Si on fait un clic gauche et que nos coordonn�es de souris coincident avec celle de notre bouton "commencer
                    finished = true; // Notre bool�en passe � true et donc on sortira de la boucle while . Donc la page du menu se fermera pour lancer le jeu.

                }
                if (Event.mouseButton.button == sf::Mouse::Left && sprite2.getGlobalBounds().contains(X, Y)){  // Si on fait un clic gauche et que nos coordonn�es de souris coincident avec celle de notre bouton "r�gles"

                    sf::RenderWindow win(sf::VideoMode(1650, 1050), "REGLES DU JEU");// On cr�e une fenetre pour afficher les r�gles du jeu
                    regles(win);  // On appelle notre fonction regles qui a pour param�tres notre fenetre cr��e ci dessus
                    win.close(); // Quand on sort de notre fonction notre fenetre se ferme.
                }
            }
        }

    }
    return;
}


/*int main (){

    sf::RenderWindow winwin(sf::VideoMode(1000, 800), "MENU"); // On cr�e notre fenetre qui servira � afficher le menu
    menu(winwin); // on appelle notre fonction menu qui a pour param�tre notre fenetre cr��e ci dessus
    winwin.close(); // Quand on sort de notre fonction notre fenetre se ferme.

}*/
