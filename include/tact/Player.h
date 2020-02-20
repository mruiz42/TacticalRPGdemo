//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_PLAYER_H
#define CIS29GROUP2GAME_PLAYER_H

#include <string>
#include "Fortress.h"
#include
class Player {
private:
    unsigned int player_id;
    unsigned int number_units;


public:
    unsigned int get_player_name() { return this->player_id; }
    unsigned int get_number_units() {return this->number_units; }

    void set_player_name(unsigned int player_id) { this->player_id = player_id; }
    void set_number_units(unsigned int number_units) {this->number_units; }

};


#endif //CIS29GROUP2GAME_PLAYER_H
