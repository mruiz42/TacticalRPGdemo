//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Knight.h"
#include<iostream>
Knight::Knight(std::string filename,int newX,int newY) : Sprite(filename)
{
    x_pos = newX;
    y_pos = newY;
    
}