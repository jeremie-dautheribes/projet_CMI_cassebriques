#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>
#include "fin.h"

void fin (sf::RenderWindow &generique){ // On crée une fonction "fin" pour lancer une fenètre avec un générique de fin lorsque l'on a gagné tous les niveaux

sf::Font font; // on initialise un fond
sf::Text text; // on initialise un texte
font.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'écrire (ici écriture basique)
text.setFont(font); //On affecte au texte , un fond
text.setString("Vous avez gagné tous les niveaux"); // Le texte vaut "vous avez gagné" (ce qui sera affiché plus tard)
text.setCharacterSize(30); // Change la taille de la police à 30
text.setStyle(sf::Text::Regular); // Pas d'effet d'écriture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect = text.getLocalBounds();
text.setOrigin(textRect.width/2,textRect.height/2);
text.setPosition(sf::Vector2f(500,250));

sf::Font font2; // on initialise un deuxieme fond
sf::Text text2; // on initialise un deuxième texte
font2.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'écrire (ici écriture basique)
text2.setFont(font2); //On affecte au texte , un fond
text2.setString("Casse_Briques © développé par Gosset Camille, Dautheribes Jérémie et Bertin Thomas"); // On change le texte par ce qui est entre guillemet
text2.setCharacterSize(26); // Change la taille de la police à 26
text2.setStyle(sf::Text::Regular); // Pas d'effet d'écriture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect2 = text2.getLocalBounds();
text2.setOrigin(textRect2.width/2,textRect2.height/2);
text2.setPosition(sf::Vector2f(500,300));

sf::Font font3; // on initialise un troisième fond
sf::Text text3; // on initialise un troisième texte
font3.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'écrire (ici écriture basique)
text3.setFont(font3); //On affecte au texte , un fond
text3.setString("Dans le cadre du projet CMI (HLSE205)"); // On change le texte par ce qui est entre guillemet
text3.setCharacterSize(26); // Change la taille de la police à 26
text3.setStyle(sf::Text::Regular); // Pas d'effet d'écriture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect3 = text3.getLocalBounds();
text3.setOrigin(textRect3.width/2,textRect3.height/2);
text3.setPosition(sf::Vector2f(500,350));

sf::Font font4; // on initialise un quatrième fond
sf::Text text4; // on initialise un quatrième texte
font4.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'écrire (ici écriture basique)
text4.setFont(font4); //On affecte au texte , un fond
text4.setString("Musiques et images conçues par nos soins"); // On change le texte par ce qui est entre guillemet
text4.setCharacterSize(26); // Change la taille de la police à 26
text4.setStyle(sf::Text::Regular); // Pas d'effet d'écriture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect4 = text4.getLocalBounds();
text4.setOrigin(textRect4.width/2,textRect4.height/2);
text4.setPosition(sf::Vector2f(500,400));

sf::Font font5; // on initialise un cinquième fond
sf::Text text5; // on initialise un cinquième texte
font5.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'écrire (ici écriture basique)
text5.setFont(font5); //On affecte au texte , un fond
text5.setString("~2016~"); // On change le texte par ce qui est entre guillemet
text5.setCharacterSize(26); // Change la taille de la police à 26
text5.setStyle(sf::Text::Regular); // Pas d'effet d'écriture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect5 = text5.getLocalBounds();
text5.setOrigin(textRect5.width/2,textRect5.height/2);
text5.setPosition(sf::Vector2f(500,450));

sf::Font font6; // on initialise un sixième fond
sf::Text text6; // on initialise un sixième texte
font6.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'écrire (ici écriture basique)
text6.setFont(font5); //On affecte au texte un fond
text6.setString("Appuyez sur n'importe quelle touche pour quitter"); // On change le texte par ce qui est entre guillemet
text6.setCharacterSize(26); // Change la taille de la police à 26
text6.setStyle(sf::Text::Regular); // Pas d'effet d'écriture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect6 = text6.getLocalBounds();
text6.setOrigin(textRect6.width/2,textRect6.height/2);
text6.setPosition(sf::Vector2f(500,500));

sf::Texture Tfigure; //On crée une texture Tfigure
sf::Sprite Sfigure; // On crée un sprite Sfigure
Tfigure.loadFromFile("images\\figure.jpg"); // On charge l'image figure dans la texture Tfigure
Sfigure.setTexture(Tfigure); //On affecte au Sprite Sfigure la texture Tfigure
Sfigure.setPosition(sf::Vector2f (100,600)); // On change la position du sprite Sfigure à 100 pixels en abscisse et 600 pixels en ordonnée
Sfigure.move(sf::Vector2f(10,10));

sf::Texture Tcmi; //On crée une texture Tcmi
sf::Sprite Scmi; // On crée un sprite Scmi
Tcmi.loadFromFile("images\\cmi.jpg"); // On charge l'image figure dans la texture Tcmi
Scmi.setTexture(Tcmi); //On affecte au Sprite Scmi la texture Tcmi
Scmi.setPosition(sf::Vector2f (500,600)); // On change la position du sprite Scmi à 500 pixels en abscisse et 600 pixels en ordonnée
Scmi.move(sf::Vector2f(10,10));

sf::Texture Tum; //On crée une texture Tum
sf::Sprite Sum; // On crée un sprite Sum
Tum.loadFromFile("images\\um.png"); // On charge l'image figure dans la texture Tum
Sum.setTexture(Tum); //On affecte au Sprite Sum la texture Tum
Sum.setPosition(sf::Vector2f (01,01)); // On change la position du sprite Sum à 01 pixels en abscisse et 01 pixels en ordonnée
Sum.move(sf::Vector2f(10,10));

sf::Texture Tfds; //On crée une texture Tfds
sf::Sprite Sfds; // On crée un sprite Sfds
Tfds.loadFromFile("images\\fds_logo.jpg"); // On charge l'image figure dans la texture Tfds
Sfds.setTexture(Tfds); //On affecte au Sprite Sfds la texture Tfds
Sfds.setPosition(sf::Vector2f (809,01)); // On change la position du sprite Sfds à 809 pixels en abscisse et 01 pixels en ordonnée
Sfds.move(sf::Vector2f(10,10));


generique.clear();
generique.draw(text);
generique.draw(text2);
generique.draw(text3);
generique.draw(text4);
generique.draw(text5);
generique.draw(text6);
generique.draw(Sfigure);
generique.draw(Scmi);
generique.draw(Sum);
generique.draw(Sfds);
generique.display();
sf::Event eventu;

bool fini = false;
while (! fini)
{
    while (generique.pollEvent(eventu))
    {
        if (eventu.type == sf::Event::Closed) // Si on appuie sur la croix
            {
                return; //la page se ferme
            }
        if(eventu.type == sf::Event::KeyPressed)
            {
                fini = true;
            }
    }
}

}


/*int main (){

    sf::RenderWindow generique(sf::VideoMode(1000, 800), "GAGNE GAGNE GAGNE");
    fin(generique);
    generique.close();

} */
