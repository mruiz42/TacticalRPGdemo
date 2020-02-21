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