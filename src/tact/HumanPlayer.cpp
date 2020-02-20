//
// Created by michael on 2/20/20.
//

#include "../../include/tact/HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player() {
    is_turn = false;
    number_units = 3;
    for (int i = 0; i < number_units; i++){
        squadron.push_back(new Ninja(fort.get_coordinate().x + i - 1, fort.get_coordinate().y + i - 1)); // figure out how to spawn different types
    }

}
HumanPlayer::HumanPlayer(Coordinate xy) : Player(xy) {
    is_turn = false;
    number_units = 3;
    for (int i = 0; i < number_units; i++){
        squadron.push_back(new Ninja(fort.get_coordinate().x + i - 1, fort.get_coordinate().y + i - 1)); // figure out how to spawn different types
    }
}

HumanPlayer::~HumanPlayer(){

}