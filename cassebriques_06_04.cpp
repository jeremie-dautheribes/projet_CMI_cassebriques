#include <SFML/Graphics.hpp>
#include <iostream>

void menu(sf::RenderWindow &window)
{
    bool finished = false;
    while (! finished) {
    //std::cout<<"\n Appuyez sur N'importe quelle touche pour entrer en Jeu \n";
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                return;
            if (Event.type == sf::Event::KeyPressed)
                finished = true;
        }
        window.clear();
        window.display();
    }
    return;
}

int main()
{
    sf::RenderWindow winwin(sf::VideoMode(800, 600), "MENU");
    menu(winwin);
    winwin.close();

    sf::Texture stop; // Texture de l'image
    stop.loadFromFile("Pause.jpg");
    sf::Sprite sprite;
    sprite.setTexture(stop); // On associe la texture à un sprite

  float x = 400;
  float y = 300;
  float rectX = 400;
  float rectY = 550;
  float vitX = 0.;
  float vitY = 5.;
  int lives = 3;
  bool pause = false;
    int brique [5][16];
    sf::RenderWindow window(sf::VideoMode(800, 600), "CasseBriques"); //initialise la fenetre
    sf::CircleShape circle(5.f); //Créer notre balle : un cercle de dimension 8
    sf::RectangleShape rectangle; //créer notre raquette : un rectangle
    sf::RectangleShape briques;
    rectangle.setSize(sf::Vector2f(115,15)); //Taille de notre raquette
    rectangle.setFillColor(sf::Color::Cyan); //Couleur de notre raquette
    rectangle.setPosition(400,550); // position initiale de notre raquette
    circle.setPosition(x,y);
    circle.setFillColor(sf::Color::Transparent); //Couleur de notre balle
    circle.setOutlineThickness(5);
    sprite.setPosition(200.f, 100.f); // Position du Sprite Pause


    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);


    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 16; j++){
            brique[i][j] = 1;
        }
    }





    window.setMouseCursorVisible(false);
    while (window.isOpen())
    {

            sf::Event event;


            float MouseX = event.mouseMove.x;
            if (pause){ // Si la variable pause est true
                circle.move(0,0); // On immobilise la balle
                while (window.isOpen() && pause){
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){ //Si une fois la pause lancée,nous voulons redemarrer, bouton gauche souris
                        pause = false;
                    }
                    window.clear();
                    window.draw(sprite); // On affiche le sprite
                    window.display();
                }

            }
            else{ // Sinon c'est le jeu normal

                circle.move(vitX,vitY);

                x += vitX;
                y += vitY;

                for (int o = 1; o < 4; o++ ) {
                    for (int l = 1; l < 14; l++) {
                        if (x>=l*55 && x<=(l*55)+45){
                            if (brique[o][l] == 1){
                                if(y+10>=80*o && y<=(80*o)+40){
                                    brique[o][l] = 0;
                                    vitY = -vitY;
                                }

                            }
                        }
                    }
                }


                if (event.type == sf::Event::MouseMoved){

                    if(MouseX+115>800){
                        rectangle.setPosition(685,550);
                    }
                    else {
                        if (MouseX<0){
                            rectangle.setPosition(0,550);
                        }
                        else {
                            rectangle.setPosition(MouseX,550);
                        }
                    }

                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window.close();
                }

                if (y>=590){
                    lives -= 1;
                    y = 540;
                    x = rectX-10;
                }
                if (x>=800){
                    vitX = -vitX;
                }
                if (y<=0){
                    vitY = -vitY;
                }
                if (x<=0){
                    vitX = -vitX;
                }

                if (y>=535) {
                    if((x>=MouseX && x<=MouseX+115) || (x>=rectX && x<=rectX+115)){
                        if (vitX == 0){
                            vitX = -5;
                            vitY = -vitY;
                        }
                        else {
                            vitY = -vitY;
                        }
                        }
                }
            }


             if(rectX+115>800){
                    rectangle.setPosition(685,550);
                }
                else if(rectX<0){
                    rectangle.setPosition(0,550);
                }

           if (sf::Mouse::isButtonPressed(sf::Mouse::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){ //Condition pour lancer l'algorithme de la pause
                pause = true;
            }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Si le bouton droite est appuyé du clavier , la raquette va à droite
            {
                rectangle.move(10,0);
                rectX += 10;
            }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Si la touche "d" du clavier est appuyée, la raquette va à droite.
        {
            rectangle.move(10,0);
            rectX +=10;
        }


         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Si le bouton "gauche" du clavier est enfoncé , la raquette va à gauche.
        {
            rectangle.move(-10,0);
            rectX -= 10;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) //Si la touche "q" du clavier est enfoncé , la raquette va à gauche
        {
            rectangle.move(-10,0);
            rectX -= 10;
        }

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
                window.setVerticalSyncEnabled(true);

        }

        window.clear(sf::Color::Blue);
        for (int o = 1; o < 4; o++ ) { // Création de lignes de briques (numérotées de 2 à 4)
            for (int l = 1; l < 14; l++) {  // Création de colonnes de briques (numérotées de 1 à 8)
                if (brique[o][l] == 1) {
                    briques.setSize(sf::Vector2f(45,30));
                    briques.setFillColor(sf::Color::White);
                    briques.setPosition(l*55,o*80);
                    window.draw(briques);
                }
            }
        }
        window.draw(circle);
        window.draw(rectangle);
        window.display();

        }


    return 0;
}
