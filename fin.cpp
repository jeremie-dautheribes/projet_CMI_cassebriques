#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>

void fin (sf::RenderWindow &generique){ // On crée une fonction "fin" pour lancer une fenètre avec un générique de fin lorsque l'on a gagné tous les niveaux

sf::Font font;
sf::Text text;
font.loadFromFile("Fonts\\introheadr-base.otf");
text.setFont(font);
text.setString("Vous avez gagné tous les niveaux");
text.setCharacterSize(30);
text.setStyle(sf::Text::Regular);

//Pour centrer le texte:
sf::FloatRect textRect = text.getLocalBounds();
text.setOrigin(textRect.width/2,textRect.height/2);
text.setPosition(sf::Vector2f(500,250));

sf::Font font2;
sf::Text text2;
font2.loadFromFile("Fonts\\introheadr-base.otf");
text2.setFont(font2);
text2.setString("Casse_Briques © développé par Gosset Camille, Dautheribes Jérémie et Bertin Thomas");
text2.setCharacterSize(26);
text2.setStyle(sf::Text::Regular);

//Pour centrer le texte:
sf::FloatRect textRect2 = text2.getLocalBounds();
text2.setOrigin(textRect2.width/2,textRect2.height/2);
text2.setPosition(sf::Vector2f(500,300));

sf::Font font3;
sf::Text text3;
font3.loadFromFile("Fonts\\introheadr-base.otf");
text3.setFont(font3);
text3.setString("Dans le cadre du projet CMI (HLSE205)");
text3.setCharacterSize(26);
text3.setStyle(sf::Text::Regular);

//Pour centrer le texte:
sf::FloatRect textRect3 = text3.getLocalBounds();
text3.setOrigin(textRect3.width/2,textRect3.height/2);
text3.setPosition(sf::Vector2f(500,350));

sf::Font font4;
sf::Text text4;
font4.loadFromFile("Fonts\\introheadr-base.otf");
text4.setFont(font4);
text4.setString("Musiques et images conçues par nos soins");
text4.setCharacterSize(26);
text4.setStyle(sf::Text::Regular);

//Pour centrer le texte:
sf::FloatRect textRect4 = text4.getLocalBounds();
text4.setOrigin(textRect4.width/2,textRect4.height/2);
text4.setPosition(sf::Vector2f(500,400));

sf::Font font5;
sf::Text text5;
font5.loadFromFile("Fonts\\introheadr-base.otf");
text5.setFont(font5);
text5.setString("~2016~");
text5.setCharacterSize(26);
text5.setStyle(sf::Text::Regular);

//Pour centrer le texte:
sf::FloatRect textRect5 = text5.getLocalBounds();
text5.setOrigin(textRect5.width/2,textRect5.height/2);
text5.setPosition(sf::Vector2f(500,450));

sf::Texture Tfigure;
sf::Sprite Sfigure;
Tfigure.loadFromFile("images\\figure.jpg");
Sfigure.setTexture(Tfigure);
Sfigure.setPosition(sf::Vector2f (100,550));
Sfigure.move(sf::Vector2f(10,10));

sf::Texture Tcmi;
sf::Sprite Scmi;
Tcmi.loadFromFile("images\\cmi.jpg");
Scmi.setTexture(Tcmi);
Scmi.setPosition(sf::Vector2f (500,550));
Scmi.move(sf::Vector2f(10,10));

sf::Texture Tum;
sf::Sprite Sum;
Tum.loadFromFile("images\\um.png");
Sum.setTexture(Tum);
Sum.setPosition(sf::Vector2f (01,01));
Sum.move(sf::Vector2f(10,10));

sf::Texture Tfds;
sf::Sprite Sfds;
Tfds.loadFromFile("images\\fds_logo.jpg");
Sfds.setTexture(Tfds);
Sfds.setPosition(sf::Vector2f (809,01));
Sfds.move(sf::Vector2f(10,10));


generique.clear();
generique.draw(text);
generique.draw(text2);
generique.draw(text3);
generique.draw(text4);
generique.draw(text5);
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


int main (){

    sf::RenderWindow generique(sf::VideoMode(1000, 800), "GAGNE GAGNE GAGNE");
    fin(generique);
    generique.close();

}
