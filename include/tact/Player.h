//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_PLAYER_H
#define CIS29GROUP2GAME_PLAYER_H

#include <string>
#include "Castle.h"
#include <SFML/Window/Joystick.hpp>

class Player {
private:
    int player_id;
    unsigned int number_units;
    sf::Joystick js;


public:
    int get_player_name() { return this->player_id; }
    unsigned int get_number_units() {return this->number_units; }
    sf::Joystick& get_js() { return this->js; }

    void set_player_name(int player_id) { this->player_id = player_id; }
    void set_number_units(unsigned int number_units) {this->number_units; }
    void set_js(sf::Joystick& js);

};


#endif //CIS29GROUP2GAME_PLAYER_H
