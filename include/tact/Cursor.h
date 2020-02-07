//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_CURSOR_H
#define CIS29GROUP2GAME_CURSOR_H
#include "Sprite.h"
#include <string>

class Cursor : public Sprite {
public:
    int x_pos;
    int y_pos;
    Cursor(std::string s, int x, int y);


};


#endif //CIS29GROUP2GAME_CURSOR_H
