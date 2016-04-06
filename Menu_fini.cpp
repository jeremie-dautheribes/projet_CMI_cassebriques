#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>

void regles (sf::RenderWindow &win)
{

    sf::Texture reglejeu;
    sf::Sprite matteo;
    reglejeu.loadFromFile("regles_jeu.jpg");
    matteo.setTexture(reglejeu);
    win.clear();
    win.draw(matteo);
    win.display();
    sf::Event fall;
    bool lecture = true;
    while (lecture){

        while (win.pollEvent(fall)){

            if (fall.type == sf::Event::Closed)
            {
                return;
            }

        }

    }



}

void menu(sf::RenderWindow &winwin)
{
    sf::Texture texture;
    sf::Texture regle;
    sf::Sprite sprite;
    sf::Sprite sprite2;
    texture.loadFromFile("start.jpg"); //Charge l'image "commencer"
    regle.loadFromFile("regles.jpg");
    sprite.setTexture(texture);
    sprite2.setTexture(regle);
    sprite.setPosition(sf::Vector2f(300,100));
    sprite2.setPosition(sf::Vector2f(300,300));
    sprite.move(sf::Vector2f(10,10));
    sprite2.move(sf::Vector2f(10,10));

    sf::Event Event;
    winwin.clear(sf::Color(103,154,198)); //affecte une couleur bleuté en fond de notre menu
    winwin.draw(sprite);
    winwin.draw(sprite2);
    winwin.display();

    bool finished = false;
    while (! finished) {

        while (winwin.pollEvent(Event))
        {

            if (Event.type == sf::Event::Closed)
            {
                return;
            }
            if (Event.type == sf::Event::MouseButtonPressed) {
                float X=Event.mouseButton.x;
                float Y=Event.mouseButton.y;


                if (Event.mouseButton.button == sf::Mouse::Left && sprite.getGlobalBounds().contains(X, Y)) {
                    finished = true;

                }
                if (Event.mouseButton.button == sf::Mouse::Left && sprite2.getGlobalBounds().contains(X, Y)){

                    sf::RenderWindow win(sf::VideoMode(1650, 1050), "REGLES DU JEU");
                    regles(win);
                    win.close();
                }
            }
        }

    }
    return;
}


int main (){

    sf::RenderWindow winwin(sf::VideoMode(1000, 800), "MENU");
    menu(winwin);
    winwin.close();

}
