//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_TANK_H
#define CIS29GROUP2GAME_TANK_H
#include "Character.h"
#include <iostream>
// High defense, low attack, low speed "front liner", has a "armor" attribute
const std::string tank_spritesheet_path = "share/sprites/tank.png";

namespace tact {
    class Tank;
}

class tact::Tank : public tact::Character {
private:
    unsigned int armor;
public:
    Tank();
    Tank(Coordinate xy);
    Tank(int x, int y);
	~Tank();
	
    unsigned int get_armor() { return this->armor; }

    void set_armor(unsigned int armor) { this->armor = armor;}
};


#endif //CIS29GROUP2GAME_TANK_H
