//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Ninja.h"
Ninja::Ninja(std::string filename) : Character(filename) {
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));

}