#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include<iostream>
#include<string>
#include <cstdlib>

void menu(sf::RenderWindow &winwin)
{
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile("C:\\Users\\PC\\Desktop\\Camille\\L1\\code\\Casse_Briques\\obj\\start.png"); //Charge l'image "commencer"
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(255,238));
    sprite.move(sf::Vector2f(5,10));
    winwin.clear(sf::Color(138,104,158)); //affecte une couleur violine en fond de notre menu
    winwin.draw(sprite);
    winwin.display();

    bool finished = false;
    while (! finished) {

    sf::Event Event;

        while (winwin.pollEvent(Event))
        {

            if (Event.type == sf::Event::Closed)
            {
                return;
            }
            if (Event.type == sf::Event::MouseButtonPressed) {
                if (Event.mouseButton.button == sf::Mouse::Left)
                    finished = true;
            }
        }

    }
    return;
}



int main()
{
    sf::RenderWindow winwin(sf::VideoMode(1080, 720, 32), "MENU");
    menu(winwin);
    winwin.close();
    
    float x= 400; // position de la balle au démarage
    float y= 300; // idem
    
    float vitX=0; // vitesse de la balle
    float vitY=10; // idem
    sf::RenderWindow window(sf::VideoMode(1200, 900), "CasseBriques"); //initialise la fenetre
    sf::CircleShape circle(8.f); //Créer notre balle : un cercle de dimension 8
    sf::RectangleShape rectangle; //créer notre raquette : un rectangle
    rectangle.setSize(sf::Vector2f(115,15)); //Taille de notre raquette
    rectangle.setFillColor(sf::Color::Cyan); //Couleur de notre raquette
    rectangle.setPosition(550,850); // position initiale de notre raquette
    circle.setPosition(x,y);
    circle.setFillColor(sf::Color::Blue); //Couleur de notre balle
    circle.setOutlineThickness(2);
    
    window.setMouseCursorVisible(false); // pour cacher la souris en jeu
    window.setVerticalSyncEnabled(true); // synchro verticale
    window.setFramerateLimit(60); // fps réglé sur 60 pour plus de fluidité que 30
    
   
    
    while (window.isOpen())
    {
        sf::Event event;
        circle.move(vitX,vitY);
        
        float MouseX=event.mouseMove.x; // récupère la position x de la souris
        
        if(event.type == sf::Event::MouseMoved) //évènement qui vérifie si la souris est bougée
        {
            
            
            if(MouseX+115>1200) // pour éviter que la raquette sorte de l'écran à droite
                rectangle.setPosition(1085,850);
            else
                rectangle.setPosition(MouseX,850); // associe la position de la souris à celle de la raquette
        }
        

        
        x+=vitX; // position de la balle
        y+=vitY; // position de la balle
        
        
        // Algo qui suit : pour gérer le rebond de la balle sur les bords et la raquette
        if(y>=900){
            if(vitX == 0){
                vitX=-10;
                vitY=-vitY;
            }
            else
                vitY=-vitY;
        }
        if (x>=1200)
            vitX= -vitX;
        if (y<=0) {
            vitY=-vitY;
        }
        if (x<=0) {
            vitX=-vitX;
        }
        
        if (y >= 835 && x>= MouseX && x<= MouseX + 115) {
                if (vitX == 0) {
                    vitX=-10;
                    vitY= -vitY;
                }
                else {
                    vitY = -vitY;
                }
            
        }
        
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { // Pour quitter le jeu en appuyant sur "échappe"
            
            window.close();
        }
                
        
        
        while (window.pollEvent(event))
        {
            
            
            
            if (event.type == sf::Event::Closed)
                window.close();
            
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Si le bouton droite est appuyé du clavier , la raquette va à droite
            {
                rectangle.move(10,0);
                window.setVerticalSyncEnabled(true);
                window.setFramerateLimit(60);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Si la touche "d" du clavier est appuyée, la raquette va à droite.
            {
                rectangle.move(10,0);
                
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Si le bouton "gauche" du clavier est enfoncé , la raquette va à gauche.
            {
                rectangle.move(-10,0);
                
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) //Si la touche "q" du clavier est enfoncé , la raquette va à gauche
            {
                rectangle.move(-8,0);
                
            }
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // Si on fait un "click gauche" , la raquette va à gauche
            {
                /*rectangle.move(-8,0);
                 window.setVerticalSyncEnabled(true);
                 window.setFramerateLimit(60);*/
                
            }
        }
        
        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.display();
    }
    
    return 0;
}
