//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Character.h"


//Character::Character(){
//    name = "";
//    level = 0;
//    experience = 0;
//    hit_points = 0;
//    mana_points = 0;
//    attack = 0;
//    defense = 0;
//    speed = 0;
//    special_attack = 0;
//    special_defense = 0;
//}

Character::Character(std::string filename){
    texture.loadFromFile(filename);
    sidebar_sprite.setTexture(texture);
    map_sprite.setTexture(texture);
    name = "";
    level = 0;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
}