//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_NINJA_H
#define CIS29GROUP2GAME_NINJA_H

#include <iostream>
#include "Character.h"

// Attack increase in forest, high critical
const std::string ninja_spritesheet_path = "share/sprites/ninja.png";

namespace tact {
    class Ninja;
}

class tact::Ninja : public tact::Character {
public:
    Ninja();
    Ninja(Coordinate xy);
    Ninja(int x, int y);
	~Ninja();
};
#endif //CIS29GROUP2GAME_NINJA_H
