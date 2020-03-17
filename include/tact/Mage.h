//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_MAGE_H
#define CIS29GROUP2GAME_MAGE_H
#include <vector>
#include <iostream>
#include "Character.h"

const std::string mage_spritesheet_path = "share/sprites/mage.png";

namespace tact {
    class Mage;
}

class tact::Mage : public tact::Character {
protected:
public:
    Mage();
    Mage(Coordinate xy);
    Mage(int x, int y);
	~Mage();
};
#endif //CIS29GROUP2GAME_MAGE_H
