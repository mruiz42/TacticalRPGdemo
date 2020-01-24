//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_TANK_H
#define CIS29GROUP2GAME_TANK_H
// High defense, low attack, low speed "front liner", has a "armor" attribute

class Tank {
private:
    unsigned int armor;
public:
    unsigned int get_armor() { return this->armor; }

    void set_armor(unsigned int armor) { this->armor = armor;}
};


#endif //CIS29GROUP2GAME_TANK_H
