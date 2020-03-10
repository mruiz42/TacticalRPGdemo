//
// Created by michael on 2/20/20.
//

#include "../../include/tact/Player.h"

Player::Player(){
    is_turn = false;
    number_units = 3;
	/*
    for (int i = 0; i < number_units; i++){
        squadron.push_back(new Ninja(fort.get_coordinate().get_x() + i - 1, fort.get_coordinate().get_y() + i - 1)); // figure out how to spawn different types
	}
	*/
     squadron.push_back(new Ninja(fort.get_coordinate().get_x() + 0 - 1, fort.get_coordinate().get_y() + 0 - 1)); 
	 squadron.push_back(new Mage(fort.get_coordinate().get_x() + 1 - 1, fort.get_coordinate().get_y() + 1 - 1)); 
	 squadron.push_back(new Tank(fort.get_coordinate().get_x() + 2 - 1, fort.get_coordinate().get_y() + 2 - 1)); 
}

Player::Player(int id, Coordinate xy) : player_id(id), fort(xy) {
    is_turn = false;
    number_units = 3;
	/*
    for (int i = 0; i < number_units; i++){
        squadron.push_back(new Ninja(fort.get_coordinate().get_x() + i - 1, fort.get_coordinate().get_y() + i - 1)); // figure out how to spawn different types
	*/
	squadron.push_back(new Tank(fort.get_coordinate().get_x() + 0 - 1, fort.get_coordinate().get_y() + 0 - 1));
	squadron.push_back(new Mage(fort.get_coordinate().get_x() + 1 - 1, fort.get_coordinate().get_y() + 1 - 1));
	squadron.push_back(new Ninja(fort.get_coordinate().get_x() + 2 - 1, fort.get_coordinate().get_y() + 2 - 1));
}

Player::~Player() {

}

Character* Player::get_next_character(int iterator) {
    for (auto i = iterator; i < squadron.size(); i++) {
        Character* c_ptr = squadron[i];
        if (c_ptr->is_moved()){
            continue;
        }
        else {
            return c_ptr;
        }
    }
    return nullptr;
}

void Player::reset_squadron_exhaustion() {
    for (auto i = 0; i < squadron.size(); i++) {
        this->squadron[i]->set_moved(false);
        this->squadron[i]->set_defending(false);
        this->squadron[i]->set_can_attack(false);
    }
}

bool Player::is_turn_end() {
    bool is_end = true;
    for (auto i = 0; i < squadron.size(); i++) {
        if (!this->squadron[i]->is_moved() || this->squadron[i]->can_attack()){
            is_end = false;
        }
    }
    return is_end;
}