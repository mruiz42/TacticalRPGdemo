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
