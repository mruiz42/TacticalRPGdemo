//
// Created by michael on 2/20/20.
//

#ifndef CIS29GROUP2GAME_PLAYER_H
#define CIS29GROUP2GAME_PLAYER_H
#include "Fortress.h"
#include "Character.h"
#include "Coordinate.h"
#include "Ninja.h"
#include "Mage.h"
#include "Tank.h"

class Player {
private:
    Fortress fort;
    std::vector<Character *> squadron;
    unsigned int player_id;
    unsigned int number_units;
    bool is_turn;
public:
    Player();
    Player(int, Coordinate);
    ~Player();
    Fortress& get_fort() { return this->fort; }
    std::vector<Character *>& get_squadron() { return this->squadron; }
    unsigned int get_player_id() { return this->player_id; }
    unsigned int get_number_units() {return this->number_units; }
    bool get_is_turn() { return this->is_turn; }

    void set_fort(Fortress fort) { this->fort = fort; }
    void set_fort_coord(int x, int y) { this->fort.set_coordinate(x, y); }
    void set_player_id(unsigned int player_id) { this->player_id = player_id; }
    void set_number_units(unsigned int number_units) {this->number_units = number_units; }
    void set_is_turn(bool is_turn) { this->is_turn = is_turn; }

    void reset_squadron_exhaustion();
    bool is_turn_end();
    Character* get_next_character(int);
};


#endif //CIS29GROUP2GAME_PLAYER_H
