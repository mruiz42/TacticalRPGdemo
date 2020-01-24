//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_MAGE_H
#define CIS29GROUP2GAME_MAGE_H
#include <vector>
#include "Character.h"
#include "Spell.h"
class Mage : public Character {
private:
    std::vector<Spell> spell_list;
protected:
public:
    std::vector<Spell> get_spell_list() { return this->spell_list; }

    void set_spell_list(std::vector<Spell> spell_list) { this->spell_list = spell_list; }

    unsigned int cast_spell(Spell mgk);
};


#endif //CIS29GROUP2GAME_MAGE_H
