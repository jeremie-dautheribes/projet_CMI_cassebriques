#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include "balle.h"



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
                    if((xBalle>=MouseX && xBalle<=MouseX+55) || (xBalle>=rectX && xBalle<=rectX+55)){
                            if((xBalle>=MouseX && xBalle<=MouseX+27) || (xBalle>=rectX && xBalle <=rectX+27))
                            {
                                if(vitX == 0)
                                vitX += 6;

                            }
                            else{
                            if(vitX == 0)
                                vitX -= 3;
                            else {
                                if(vitX > 0)
                                    vitX = 0;
                            }
                            vitY = -vitY;
                            }
                        }
                        else {
                            if((xBalle>=MouseX+60 && xBalle<=MouseX+115) || (xBalle>=rectX+60 && xBalle<=rectX+115)){
                                    if((xBalle>=MouseX+30 && xBalle<=MouseX+115) || (xBalle>= rectX+30 && xBalle <=rectX+115))
                                       {
                                           if(vitX == 0)
                                            vitX -=6;
                                       }
                                       else{
                                            if(vitX == 0)
                                            vitX += 3;
                                else {
                                    if(vitX < 0)
                                        vitX = 0;
                                }
                                       }
                            vitY = -vitY;
                            }

                        }
                        }
                else {

                    if (yBalle>=540 && yBalle<=560){
                        if((xBalle>=MouseX && xBalle<=MouseX+115) ||(xBalle>=rectX && xBalle<=rectX+115)){
                            vitY = -5;
                            vitX = -vitX;
                    }
                }
                }
    }
