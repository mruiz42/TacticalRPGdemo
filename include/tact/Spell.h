//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_SPELL_H
#define CIS29GROUP2GAME_SPELL_H
#include "string"
namespace tact {
    class Spell;
}
class Spell {
private:
    std::string spell_name;
    unsigned int cost;
    float accuracy;
    float crit_ratio;
    float damage_multiplier;
public:
    // someone else can do accessor and mutators here, im tired : D
};


#endif //CIS29GROUP2GAME_SPELL_H
