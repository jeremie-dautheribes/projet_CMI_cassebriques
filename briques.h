#ifndef BRIQUES_H_INCLUDED
#define BRIQUES_H_INCLUDED

void initialisationBrique (int** tab, int nbLignes, int nbColonnes );
void disparitonRebondSurBrique (int** brique,float &x, float &y,float &vitX, float &vitY, int nbLignes, int nbColonnes);
void creationBrique(sf::RenderWindow &window,sf::RectangleShape Briques, int **brique, int nbLignes, int nbColonnes);

#endif // BRIQUES_H_INCLUDED
