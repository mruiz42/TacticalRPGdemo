//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_NINJA_H
#define CIS29GROUP2GAME_NINJA_H
#include "Character.h"
// Attack increase in forest, high critical
const std::string ninja_spritesheet_path = "share/sprites/ninja.png";

class Ninja : public Character {
private:
public:
    Ninja();
    Ninja(std::string filename);
};
#endif //CIS29GROUP2GAME_NINJA_H
