//
// Created by michael on 2/20/20.
//

#include "../../include/tact/HumanPlayer.h"

HumanPlayer::HumanPlayer() {
    player_id = NULL;                   // Initialized later in Game constructor
    is_turn = false;
    number_units = 2;
    squadron = new Ninja[number_units]; // figure out how to spawn different types
    for (int i = 0; i < number_units; i++){
        squadron[i].set_coordinate(fort.get_coordinate().x + i - 1, fort.get_coordinate().y + i - 1);
    }

}