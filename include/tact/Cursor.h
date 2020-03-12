//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_CURSOR_H
#define CIS29GROUP2GAME_CURSOR_H
#include "Sprite.h"
#include "Coordinate.h"
#include <string>
#include <iostream>
const std::string cur_path = "share/sprites/cursor.png";

class Cursor : public Coordinate {
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Cursor();
    Cursor(int x, int y);
    int get_tile_x() { return this->x/32; }
    int get_tile_y() { return this->y/32; }
    Coordinate get_tile_coordinate();
    sf::Sprite get_sprite() { return this->sprite; }
    virtual void moveSprite(float x, float y);
    void jump_to(int, int);
    void jump_to(Coordinate);
    friend std::ostream& operator<< (std::ostream& out, const Cursor& cursor);
};


#endif //CIS29GROUP2GAME_CURSOR_H
