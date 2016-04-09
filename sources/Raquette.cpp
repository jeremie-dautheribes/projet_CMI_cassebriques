#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include "raquette.h"


void raquetteSouris (sf::Event &event, sf::RectangleShape &rectangle, float &rectX) { // mouvement de la raquette avec la souris


    float MouseX= event.mouseMove.x;

    if (event.type == sf::Event::MouseMoved){
        rectX = MouseX ;
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
