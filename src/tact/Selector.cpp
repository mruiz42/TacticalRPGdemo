//
// Created by michael on 2/21/20.
//

#include "../../include/tact/Selector.h"

using namespace tact;

void Selector::clear() {
    this->selection = nullptr;
    this->target = nullptr;
    this->selection_pos = nullptr;
    this->target_pos = nullptr;
}

void Selector::clear_selection() {
    this->selection = nullptr;
    this->target_pos = nullptr;
}

void Selector::clear_target() {
    this->target = nullptr;
    this->target_pos = nullptr;
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

Coordinate Selector::get_delta_pos(Coordinate origin, Coordinate final) {
    return final - origin;
}