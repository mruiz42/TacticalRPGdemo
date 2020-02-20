//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_HUMANPLAYER_H
#define CIS29GROUP2GAME_HUMANPLAYER_H

#include <string>
#include "Fortress.h"
#include "Character.h"
#include "Controller.h"

class HumanPlayer {
private:
    Fortress fort;
    Character** characters; // is this right? If i want a 'dynamic array' of new Characters?
    unsigned int player_id;
    unsigned int number_units;
    Controller controller;
    bool is_turn;
public:
    HumanPlayer();

    Fortress get_fort() { return this->fort; }
    unsigned int get_player_id() { return this->player_id; }
    unsigned int get_number_units() {return this->number_units; }
    Controller& get_controller() { return this->controller;}

    void set_fort(Fortress fort) { this->fort = fort; }
    void set_player_id(unsigned int player_id) { this->player_id = player_id; }
    void set_number_units(unsigned int number_units) {this->number_units; }
    void set_controller(Controller& controller) { this->controller = controller; }
};


#endif //CIS29GROUP2GAME_HUMANPLAYER_H
