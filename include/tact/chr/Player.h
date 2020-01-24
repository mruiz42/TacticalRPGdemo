//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_PLAYER_H
#define CIS29GROUP2GAME_PLAYER_H

#include <string>
#include "Castle.h"
class Player {
private:
    std::string player_name;
    unsigned int number_units;

public:
    std::string get_player_name() { return this->player_name; }
    unsigned int get_number_units() {return this->number_units; }

    void set_player_name(std::string player_name) { this->player_name = player_name; }
    void set_number_units(unsigned int number_units) {this->number_units; }
};


#endif //CIS29GROUP2GAME_PLAYER_H
