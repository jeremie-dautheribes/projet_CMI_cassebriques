#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>


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
