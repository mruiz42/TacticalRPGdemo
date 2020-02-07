//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Cursor.h"

Cursor::Cursor(std::string s, int x, int y) : Sprite(s) {
    this->x_pos = x;
    this->y_pos = y;
}