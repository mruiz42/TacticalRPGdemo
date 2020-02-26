//
// Created by michael on 2/21/20.
//

#include "../../include/tact/Selector.h"

void Selector::clear() {
    this->selection = nullptr;
    this->target = nullptr;
}

void Selector::clear_selection() {
    this->selection = nullptr;
}

void Selector::clear_target() {
    this->target = nullptr;
}

bool Selector::is_selection_empty() {
    return this->selection == nullptr;
}
bool Selector::is_target_empty() {
    return this->target == nullptr;
}

bool Selector::is_empty() {
    return this->selection == nullptr && this->target == nullptr;
}

void Selector::perform_battle() {
    int damage_inflicted = 0;
    float luck_percentage = this->selection->get_luck();
    bool critical_hit = false;
    bool successful_hit = true;
    // do some rand call to see if it is a critical hit
    float multiplier = 0.0;




    if (successful_hit) {

        if (critical_hit) {
            damage_inflicted = (this->selection->get_attack() * multiplier) - this->selection->get_defense();
        } else {
            damage_inflicted = this->selection->get_attack() - this->selection->get_defense();
        }

    }




    if (damage_inflicted > this->target->get_hit_points()) {
        // call delete character and remove from squadron
    }

}