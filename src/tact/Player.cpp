//
// Created by michael on 2/20/20.
//

#include "../../include/tact/Player.h"

Player::Player(){
    is_turn = false;
    number_units = 3;
}

Player::Player(int id, Coordinate xy) : player_id(id), fort(xy) {

}

Player::~Player() {

}

Character* Player::get_next_character(int iterator) {
    for (auto i = iterator; i < squadron.size(); i++) {
        Character* c_ptr = squadron[i];
        if (c_ptr->is_exhausted()){
            continue;
        }
        else {
            return c_ptr;
        }
    }
}

void Player::reset_squaderon_exhaustion() {
    for (auto i = 0; i < squadron.size(); i++) {
        this->squadron[i]->set_exhausted(false);
    }
}

bool Player::is_turn_end() {
    bool is_end = true;
    for (auto i = 0; i < squadron.size(); i++) {
        if (!this->squadron[i]->is_exhausted()){
            is_end = false;
        }
    }
    return is_end;
}