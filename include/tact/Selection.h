//
// Created by michael on 2/21/20.
//

#ifndef CIS29GROUP2GAME_SELECTION_H
#define CIS29GROUP2GAME_SELECTION_H
#include "Character.h"

class Selection {
private:
    Character* selection;
    Character* target;
public:
    Selection() : selection(nullptr), target(nullptr) {}
    Character& get_selection() { return *this->selection; }
    Character& get_target() { return *this->target; }

    void set_selection(Character selection) { this->selection = &selection; }
    void set_target(Character target) {this->target = &target; }

    void clear();
};


#endif //CIS29GROUP2GAME_SELECTION_H
