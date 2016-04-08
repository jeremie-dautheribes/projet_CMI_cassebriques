#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>

template<typename T> std::string number_to_string(const T& n) { //Pouvoir faire apparaître la variable lives en jeu à côté de "Lives = "
    std::ostringstream stream;
    stream << n;
    return stream.str();
}

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

void raquetteSouris (sf::Event &event, sf::RectangleShape &rectangle, float &rectX) { // mouvement de la raquette avec la souris
    
    
    float MouseX= event.mouseMove.x;
    
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
    
    if(rectX+115>800){
            rectangle.setPosition(685,550);
            }
            else {
                if(rectX<0){
                    rectangle.setPosition(0,550);
                }
            }
    return;
}

 void rebond(float &xBalle, float &yBalle, float &MouseX, float &vitX, float &vitY, float &rectX){
                if (xBalle>=800){
                    vitX = -vitX;
                }
                if (yBalle<=0){
                    vitY = -vitY;
                }
                if (xBalle<=0){
                    vitX = -vitX;
                }

                if (yBalle==540) {
                    if((xBalle>=MouseX && xBalle<=MouseX+115) || (xBalle>=rectX && xBalle<=rectX+115)){
                        if (vitX == 0){
                            vitX = -3;
                            vitY = -vitY;
                        }
                        else {
                            vitY = -vitY;

                        }
                        }
                }
                else {

                    if (yBalle>=540){
                        if((xBalle>=MouseX && xBalle<=MouseX+115) ||(xBalle>=rectX && xBalle<=rectX+115)){
                            vitY = -vitY;
                            vitX = -vitX;
                    }
                }
                }
    }
    
    
    


void menuPause (sf::Texture &stop, sf::Sprite &sprite, sf::RenderWindow &window, bool &pause, sf::CircleShape &circle) {
    
    stop.loadFromFile("Pause.jpg");
    sprite.setTexture(stop);
    
    circle.move(0,0); // On immobilise la balle
    while (window.isOpen() && pause){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){ //Si une fois la pause lancée,nous voulons redemarrer, bouton gauche souris
            pause = false;
        }
        window.clear();
        window.draw(sprite); // On affiche le sprite
        window.display();
    }
    
    
    return;
}

void initialisationBrique (int** tab, int nbLignes, int nbColonnes ) {
    
    for(int i = 0; i < nbLignes; i++){
        for(int j = 0; j < nbColonnes; j++){
            if(i%3 != j%3){
                tab[i][j] = 1;
            }
            
            else {
                tab[i][j] = 2;
            }
        }
    }

}


void disparitonRebondSurBrique (int** brique,float &x, float &y,float &vitX, float &vitY, int nbLignes, int nbColonnes) {
    
    for (int o = 1; o < nbLignes; o++ ) { // Création de lignes de briques (numérotées de 2 à 4)
        for (int l = 1; l < nbColonnes; l++) {  // Création de colonnes de briques (numérotées de 1 à 8)
            if (x+10>=l*55 && x<=(l*55)+45){
                if (brique[o][l] == 1 || brique[o][l] == 2){
                    if(y+10==80*o || y==(80*o)+30){
                        brique[o][l] = brique[o][l] - 1 ;
                        vitY=-vitY;
                    }
                    else {
                        if(y+10>80*o && y+10<(80*o)+30){
                            brique[o][l] = brique[o][l] - 1;
                            vitX=-vitX;
                        }
                    }
                    
                    
                }
            }
        }
    }
}

void creationBrique(sf::RenderWindow &window,sf::RectangleShape Briques, int **brique, int nbLignes, int nbColonnes) {

    for (int o = 1; o < nbLignes; o++ ) { // Création de lignes de briques (numérotées de 2 à 4)
        for (int l = 1; l < nbColonnes; l++) {  // Création de colonnes de briques (numérotées de 1 à 8)
            if (brique[o][l] == 2) {
                Briques.setSize(sf::Vector2f(45,30));
                Briques.setFillColor(sf::Color::Red);
                Briques.setPosition(l*55,o*80);
                window.draw(Briques);
            }
            else{
                if(brique[o][l] == 1){
                    Briques.setSize(sf::Vector2f(45,30));
                    Briques.setFillColor(sf::Color::White);
                    Briques.setPosition(l*55,o*80);
                    window.draw(Briques);
                }
            }
        }
    }
}



int main()
{
    int lives = 3;
    sf::RenderWindow winwin(sf::VideoMode(800, 600), "MENU");
    menu(winwin);
    winwin.close();
    sf:: Font font;
    sf:: Text text;
    font.loadFromFile("introrustg-base2line.otf");
    text.setFont(font);
    text.setString("Lives = " + number_to_string(lives));
    text.setCharacterSize(24);
    text.setColor(sf::Color::Black);
    
    sf::Texture stop; // Texture de l'image
    stop.loadFromFile("Pause.jpg");
    sf::Sprite sprite;
    sprite.setTexture(stop); // On associe la texture à un sprite
    
    float x = 400;
    float y = 300;
    float rectX = 400;
    float vitX = 0.;
    float vitY = 5.;
    bool pause = false;
    sf::RenderWindow window(sf::VideoMode(800, 600), "CasseBriques"); //initialise la fenetre
    sf::CircleShape circle(5.f); //Créer notre balle : un cercle de dimension 8
    sf::RectangleShape rectangle; //créer notre raquette : un rectangle
    sf::RectangleShape Briques;
    rectangle.setSize(sf::Vector2f(115,15)); //Taille de notre raquette
    rectangle.setFillColor(sf::Color::Cyan); //Couleur de notre raquette
    rectangle.setPosition(400,550); // position initiale de notre raquette
    circle.setPosition(x,y);
    circle.setFillColor(sf::Color::Transparent); //Couleur de notre balle
    circle.setOutlineThickness(5);
    sprite.setPosition(200.f, 100.f); // Position du Sprite Pause
    
    
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    
    
    
    
    
    
    
    window.setMouseCursorVisible(false);
    
    int** brique= new int*[5];
    for(int k(0); k < 5; k++)
        brique[k]= new int[16];
    
    initialisationBrique(brique, 5, 16);
    
    while (window.isOpen())
    {
        
        sf::Event event;
        
        
        float MouseX = event.mouseMove.x;
        if (pause){ // Si la variable pause est true
            menuPause(stop, sprite, window, pause, circle);
            
        }
        
        else{ // Sinon c'est le jeu normal
            
            circle.move(vitX,vitY);
            
            x += vitX;
            y += vitY;
            
            
            
            disparitonRebondSurBrique(brique, x, y, vitX, vitY, 4, 14);
            
            
            
            raquetteSouris(event,rectangle,rectX);
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            
         rebond(x, y, MouseX ,vitX ,vitY ,rectX);
            
        }
        
        
        
        
        
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){ //Condition pour lancer l'algorithme de la pause
            pause = true;
        }



        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) // Si le bouton droite est appuyé du clavier , la raquette va à droite
        {
            rectangle.move(10,0);
            rectX += 10;
        }
        
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))) // Si le bouton "gauche" du clavier est enfoncé , la raquette va à gauche.
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
      
        
        creationBrique(window, Briques, brique, 4, 14);
        
        window.draw(circle);
        window.draw(rectangle);
        window.draw(text);
        window.display();
        
    }
    
    
    return 0;
}
