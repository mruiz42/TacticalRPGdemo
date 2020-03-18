//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_CURSOR_H
#define CIS29GROUP2GAME_CURSOR_H

#include <string>
#include <iostream>
#include "tact/Sprite.h"
#include "Coordinate.h"

class Cursor : public Coordinate {
private:
    int texture_size;
    std::string cur_path;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Cursor();
    Cursor(std::string cur_path);
    Cursor(int x, int y);
    Cursor(int x, int y, int texture_size);
    Cursor(int x, int y, std::string cur_path);
    Cursor(int x, int y, int texture_size, std::string cur_path);

    int get_texture_size() { return this->texture_size; }
    std::string get_cur_path() { return this->cur_path; }
    int get_tile_x() { return this->x/texture_size; }
    int get_tile_y() { return this->y/texture_size; }
    Coordinate get_tile_coordinate();
    sf::Sprite get_sprite() { return this->sprite; }

    void setTexture_size(int texture_size) { this->texture_size = texture_size; }
    void set_cur_path(std::string cur_path) { this->cur_path = cur_path; }

    int load_texture();

    virtual void move_Sprite(float x, float y);
    void jump_to(int, int);
    void jump_to(Coordinate);
    friend std::ostream& operator<< (std::ostream& out, const Cursor& cursor);

	//gets map coordinate so char can walk
    float get_map_x() const { return static_cast<float>(this->x)*texture_size; }
    float get_map_y() const {     return static_cast<float>(this->y)*texture_size; }
};


#endif //CIS29GROUP2GAME_CURSOR_H
