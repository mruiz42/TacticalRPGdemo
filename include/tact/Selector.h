//
// Created by michael on 2/21/20.
//

#ifndef CIS29GROUP2GAME_SELECTOR_H
#define CIS29GROUP2GAME_SELECTOR_H
#include "Character.h"

class Selector {
private:
    Character* selection;
    Character* target;
public:
    Selector() : selection(nullptr), target(nullptr) {}
    Character& get_selection() { return *this->selection; }
    Character& get_target() { return *this->target; }

    void set_selection(Character* selection) { this->selection = selection; }
    void set_target(Character* target) { this->target = target; }

    void clear();
    void clear_selection();
    void clear_target();

    bool is_empty();

    bool is_target_empty();

    bool is_selection_empty();
};


#endif //CIS29GROUP2GAME_SELECTOR_H
