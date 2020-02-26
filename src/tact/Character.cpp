//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Character.h"


Character::Character() : xy(0,0) {
    name = "";
    level = 0;
    attack_on = false;
    moved = false;
    defending = false;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
    luck = 0;
}

Character::Character(Coordinate xy) : xy(xy) {
    name = "";
    level = 0;
    attack_on = false;
    moved = false;
    defending = false;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
    luck = 0;
}

Character::Character(int x, int y) : xy(x, y) {
    name = "";
    level = 0;
    attack_on = false;
    moved = false;
    defending = false;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
    luck = 0;
}

Character::Character(std::string filename){
    texture.loadFromFile(filename);
    sidebar_sprite1.setTexture(texture);
    sidebar_sprite2.setTexture(texture);
    map_sprite.setTexture(texture);
    name = "";
    attack_on = false;
    moved = false;
    defending = false;
    level = 0;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
    luck = 0;
}

void Character::set_coordinate(int x, int y) {
    this->xy.set_x(x);
    this->xy.set_y(y);
}

//void Character::set_coordinate(Coordinate coordinate) {
//    this->xy.set_x(coordinate.get_x());
//    this->xy.set_y(coordinate.get_y());
//}

