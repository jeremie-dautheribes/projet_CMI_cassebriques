#ifndef PERDU_H_INCLUDED
#define PERDU_H_INCLUDED

void menuperdu (sf::RenderWindow &fenetre);
void perdu (sf::Event &event, sf::RenderWindow &window, sf::RectangleShape &rectangle, sf::CircleShape &circle, sf::RectangleShape &Briques, int** brique, int &lives, float& xBalle, float& yBalle, float &vitX, float &vitY, bool &perd, float &rectX);

#endif // PERDU_H_INCLUDED
