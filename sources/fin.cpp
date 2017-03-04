#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>
#include "../includes/fin.h"

void fin (sf::RenderWindow &generique,sf::RenderWindow &window){ // On cr�e une fonction "fin" pour lancer une fen�tre avec un g�n�rique de fin lorsque l'on a gagn� tous les niveaux

sf::Font font; // on initialise un fond
sf::Text text; // on initialise un texte
font.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'�crire (ici �criture basique)
text.setFont(font); //On affecte au texte , un fond
text.setString("Vous avez gagn� tous les niveaux"); // Le texte vaut "vous avez gagn�" (ce qui sera affich� plus tard)
text.setCharacterSize(30); // Change la taille de la police � 30
text.setStyle(sf::Text::Regular); // Pas d'effet d'�criture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect = text.getLocalBounds();
text.setOrigin(textRect.width/2,textRect.height/2);
text.setPosition(sf::Vector2f(500,250));

sf::Font font2; // on initialise un deuxieme fond
sf::Text text2; // on initialise un deuxi�me texte
font2.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'�crire (ici �criture basique)
text2.setFont(font2); //On affecte au texte , un fond
text2.setString("Casse_Briques � d�velopp� par Gosset Camille, Dautheribes J�r�mie et Bertin Thomas"); // On change le texte par ce qui est entre guillemet
text2.setCharacterSize(26); // Change la taille de la police � 26
text2.setStyle(sf::Text::Regular); // Pas d'effet d'�criture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect2 = text2.getLocalBounds();
text2.setOrigin(textRect2.width/2,textRect2.height/2);
text2.setPosition(sf::Vector2f(500,300));

sf::Font font3; // on initialise un troisi�me fond
sf::Text text3; // on initialise un troisi�me texte
font3.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'�crire (ici �criture basique)
text3.setFont(font3); //On affecte au texte , un fond
text3.setString("Dans le cadre du projet CMI (HLSE205)"); // On change le texte par ce qui est entre guillemet
text3.setCharacterSize(26); // Change la taille de la police � 26
text3.setStyle(sf::Text::Regular); // Pas d'effet d'�criture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect3 = text3.getLocalBounds();
text3.setOrigin(textRect3.width/2,textRect3.height/2);
text3.setPosition(sf::Vector2f(500,350));

sf::Font font4; // on initialise un quatri�me fond
sf::Text text4; // on initialise un quatri�me texte
font4.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'�crire (ici �criture basique)
text4.setFont(font4); //On affecte au texte , un fond
text4.setString("Musiques et images con�ues par nos soins"); // On change le texte par ce qui est entre guillemet
text4.setCharacterSize(26); // Change la taille de la police � 26
text4.setStyle(sf::Text::Regular); // Pas d'effet d'�criture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect4 = text4.getLocalBounds();
text4.setOrigin(textRect4.width/2,textRect4.height/2);
text4.setPosition(sf::Vector2f(500,400));

sf::Font font5; // on initialise un cinqui�me fond
sf::Text text5; // on initialise un cinqui�me texte
font5.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'�crire (ici �criture basique)
text5.setFont(font5); //On affecte au texte , un fond
text5.setString("~2016~"); // On change le texte par ce qui est entre guillemet
text5.setCharacterSize(26); // Change la taille de la police � 26
text5.setStyle(sf::Text::Regular); // Pas d'effet d'�criture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect5 = text5.getLocalBounds();
text5.setOrigin(textRect5.width/2,textRect5.height/2);
text5.setPosition(sf::Vector2f(500,450));

sf::Font font6; // on initialise un sixi�me fond
sf::Text text6; // on initialise un sixi�me texte
font6.loadFromFile("Fonts\\introheadr-base.otf"); //On charge le type d'�crire (ici �criture basique)
text6.setFont(font5); //On affecte au texte un fond
text6.setString("Appuyez sur n'importe quelle touche pour quitter"); // On change le texte par ce qui est entre guillemet
text6.setCharacterSize(26); // Change la taille de la police � 26
text6.setStyle(sf::Text::Regular); // Pas d'effet d'�criture : on a une police en "regular"

//Pour centrer le texte:
sf::FloatRect textRect6 = text6.getLocalBounds();
text6.setOrigin(textRect6.width/2,textRect6.height/2);
text6.setPosition(sf::Vector2f(500,500));

sf::Texture Tfigure; //On cr�e une texture Tfigure
sf::Sprite Sfigure; // On cr�e un sprite Sfigure
Tfigure.loadFromFile("images\\figure.jpg"); // On charge l'image figure dans la texture Tfigure
Sfigure.setTexture(Tfigure); //On affecte au Sprite Sfigure la texture Tfigure
Sfigure.setPosition(sf::Vector2f (100,600)); // On change la position du sprite Sfigure � 100 pixels en abscisse et 600 pixels en ordonn�e
Sfigure.move(sf::Vector2f(10,10));

sf::Texture Tcmi; //On cr�e une texture Tcmi
sf::Sprite Scmi; // On cr�e un sprite Scmi
Tcmi.loadFromFile("images\\cmi.jpg"); // On charge l'image figure dans la texture Tcmi
Scmi.setTexture(Tcmi); //On affecte au Sprite Scmi la texture Tcmi
Scmi.setPosition(sf::Vector2f (500,600)); // On change la position du sprite Scmi � 500 pixels en abscisse et 600 pixels en ordonn�e
Scmi.move(sf::Vector2f(10,10));

sf::Texture Tum; //On cr�e une texture Tum
sf::Sprite Sum; // On cr�e un sprite Sum
Tum.loadFromFile("images\\um.png"); // On charge l'image figure dans la texture Tum
Sum.setTexture(Tum); //On affecte au Sprite Sum la texture Tum
Sum.setPosition(sf::Vector2f (01,01)); // On change la position du sprite Sum � 01 pixels en abscisse et 01 pixels en ordonn�e
Sum.move(sf::Vector2f(10,10));

sf::Texture Tfds; //On cr�e une texture Tfds
sf::Sprite Sfds; // On cr�e un sprite Sfds
Tfds.loadFromFile("images\\fds_logo.jpg"); // On charge l'image figure dans la texture Tfds
Sfds.setTexture(Tfds); //On affecte au Sprite Sfds la texture Tfds
Sfds.setPosition(sf::Vector2f (809,01)); // On change la position du sprite Sfds � 809 pixels en abscisse et 01 pixels en ordonn�e
Sfds.move(sf::Vector2f(10,10));

sf::Texture TBender;
sf::Sprite SBender;
TBender.loadFromFile("images\\applauseb.jpg");
SBender.setTexture(TBender);
SBender.setPosition(sf::Vector2f(250,190));
SBender.setColor(sf::Color(255,255,255,128));

sf::SoundBuffer applause;
sf::Sound applaudir;
applause.loadFromFile("sons\\applaudissement_fin.ogg");
applaudir.setBuffer(applause);
applaudir.play();


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
generique.draw(SBender);
generique.display();
sf::Event eventu;

bool fini = false;
while (! fini)
{
    while (generique.pollEvent(eventu))
    {
        if (eventu.type == sf::Event::Closed) // Si on appuie sur la croix
            {
                window.close();
                return; //la page se ferme
            }
        if(eventu.type == sf::Event::KeyPressed)
            {
                window.close();
                fini = true;
            }
    }
}

}
