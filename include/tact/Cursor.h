//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_CURSOR_H
#define CIS29GROUP2GAME_CURSOR_H
#include "Sprite.h"
#include <string>
#include "Coordinate.h"
#include <iostream>
const std::string cur_path = "share/sprites/cursor.png";

class Cursor : public Coordinate {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    Coordinate xy;

public:
    Cursor();
    Cursor(int x, int y);
    virtual void moveSprite(float x, float y);
    int get_tile_x() { return this->xy.get_x()/32; }
    int get_tile_y() { return this->xy.get_y()/32; }
//    Coordinate& get_coordinate() { return this-> xy; }
//    Coordinate& get_tile_coordinate() { return this->xy.get_tile_coordinate(); }
    sf::Sprite get_sprite() { return this->sprite; }
//    void set_x(int x) { this->xy.x = x; }
//    void set_y(int y) { this->xy.y = y; }
//    void set_coordinate(int x, int y);
//    void set_coordinate(Coordinate& coordinate) { this->xy = coordinate; }

    void jump_to(float, float);
};


#endif //CIS29GROUP2GAME_CURSOR_H
