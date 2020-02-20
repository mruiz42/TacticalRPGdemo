//
// Created by michael on 2/20/20.
//

#include "../../include/tact/Player.h"

Player::Player(){
    is_turn = false;
    number_units = 3;
}
Player::Player(Coordinate xy) : fort(xy) {}

Player::~Player() {

}
