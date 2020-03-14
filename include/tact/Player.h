//
// Created by michael on 2/20/20.
//

#ifndef CIS29GROUP2GAME_PLAYER_H
#define CIS29GROUP2GAME_PLAYER_H
#include "SpawnPoint.h"
#include "Character.h"
#include "../Coordinate.h"
#include "Ninja.h"
#include "Mage.h"
#include "Tank.h"

namespace tact {
    class Player;
}

class tact::Player {
private:
    SpawnPoint spawn_point;
    std::vector<Character *> squadron;
    unsigned int player_id;
    unsigned int number_units;
    bool is_turn;
public:
    Player();
    Player(int, Coordinate);
    ~Player();
    SpawnPoint& get_spawn_point() { return this->spawn_point; }
    std::vector<Character *>& get_squadron() { return this->squadron; }
    unsigned int get_player_id() { return this->player_id; }
    unsigned int get_number_units() {return this->number_units; }
    bool get_is_turn() { return this->is_turn; }

    void set_spawn_point(SpawnPoint spawn_point) { this->spawn_point = spawn_point; }
    void set_spawn_point_coord(int x, int y) { this->spawn_point.set_coordinate(x, y); }
    void set_player_id(unsigned int player_id) { this->player_id = player_id; }
    void set_number_units(unsigned int number_units) {this->number_units = number_units; }
    void set_is_turn(bool is_turn) { this->is_turn = is_turn; }

    void reset_squadron_exhaustion();
    bool is_turn_end();
    Character* get_next_character(int);
};


#endif //CIS29GROUP2GAME_PLAYER_H
