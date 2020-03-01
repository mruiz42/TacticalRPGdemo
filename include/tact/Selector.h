//
// Created by michael on 2/21/20.
//

#ifndef CIS29GROUP2GAME_SELECTOR_H
#define CIS29GROUP2GAME_SELECTOR_H
#include "Character.h"

class Selector {
private:
    Character* selection;
    Coordinate selection_pos;
    Character* target;
    Coordinate target_pos;
public:
    // Constructors
    Selector() : selection(nullptr), target(nullptr) {}
    // Accessors
    Character& get_selection() { return *this->selection; }
    Coordinate get_selection_pos() { return this->selection_pos; }
    Character& get_target() { return *this->target; }
    Coordinate get_target_pos() { return this->target_pos; }

    // Mutators
    void set_selection(Character* selection) { this->selection = selection; }
    void set_selection_pos(Coordinate selection_pos) { this->selection_pos = selection_pos; }
    void set_target(Character* target) { this->target = target; }
    void set_target_pos(Coordinate target_pos) { this->target_pos = target_pos; }
    // Other methods
    Coordinate get_delta_pos(Coordinate, Coordinate);
    void clear();
    void clear_selection();
    void clear_target();
    bool is_empty();
    bool is_target_empty();
    bool is_selection_empty();
};


#endif //CIS29GROUP2GAME_SELECTOR_H
