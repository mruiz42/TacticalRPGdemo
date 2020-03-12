//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_MAGE_H
#define CIS29GROUP2GAME_MAGE_H
#include <vector>
#include <iostream>
#include "Character.h"
#include "Spell.h"

const std::string mage_spritesheet_path = "share/sprites/mage.png";

namespace tact {
    class Mage;
}

class tact::Mage : public tact::Character {
private:
    std::vector<Spell> spell_list;
protected:
public:
    Mage();
    Mage(Coordinate xy);
    Mage(int x, int y);

    std::vector<Spell> get_spell_list() { return this->spell_list; }

    void set_spell_list(std::vector<Spell> spell_list) { this->spell_list = spell_list; }

    unsigned int cast_spell(Spell mgk);
};


#endif //CIS29GROUP2GAME_MAGE_H
