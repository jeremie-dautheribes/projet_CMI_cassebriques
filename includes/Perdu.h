#ifndef PERDU_H_INCLUDED
#define PERDU_H_INCLUDED

void menuperdu (sf::RenderWindow &fenetre,sf::RenderWindow &window,int **brique,int &niveau);
void perdu (sf::Event &event,sf::Sprite &Sbackground, sf::RenderWindow &window, sf::RectangleShape &rectangle,sf::RectangleShape &bord, sf::CircleShape &circle, sf::RectangleShape &Briques, int** brique, int &lives, float& xBalle, float& yBalle, float &vitX, float &vitY, bool &perd, float &rectX,float &MouseX,int &niveau);

#endif // PERDU_H_INCLUDED
