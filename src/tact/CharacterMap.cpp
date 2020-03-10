//
// Created by michael on 2/17/20.
//

#include "../../include/tact/CharacterMap.h"
#include "../../include/tact/Ninja.h"
#include "../../include/tact/Mage.h"
#include <iostream>
CharacterMap::CharacterMap() {
    map.resize(22);
    for (int y = 0; y < 22; ++y){
        map[y].resize(32);
        for (int x = 0; x < 32; ++x){
            map[y][x] = nullptr;
        }
    }


//    for (int y = 0; y < 22; ++y){
//        for (int x = 0; x < 32; ++x){
//            std::cout << map[y][x] << "\t";
//        }
//        std::cout << std::endl;
//    }
}

CharacterMap::~CharacterMap() {
    for (int y = 0; y < 22; ++y){
        for (int x = 0; x < 32; ++x) {
            if (map[y][x] != nullptr){
                delete map[y][x];
            }
        }
    }
}

std::vector<std::vector<Character*> >& CharacterMap::get_map(){
    return this->map;
}

void CharacterMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int y = 0; y < 22; ++y){
        for (int x = 0; x < 32; ++x){
            if (map[y][x] != nullptr) {
                map[y][x]->get_map_sprite().setOrigin(map[y][x]->get_map_sprite().getLocalBounds().width, 0);
                map[y][x]->get_map_sprite().setScale({-1,1});
                map[y][x]->get_map_sprite().setPosition(x*32,y*32);
                target.draw(map[y][x]->get_map_sprite(), states);
            }
        }
    }
}

Character* CharacterMap::get_character_at(int x, int y){
    return this->map[y][x];
}

Character& CharacterMap::get_character_address_at(Coordinate coordinate){
    return *this->map[coordinate.get_y()][coordinate.get_x()];
}

Character* CharacterMap::get_character_at(Coordinate coordinate) {
    return this->map[coordinate.get_y()][coordinate.get_x()];
}

void CharacterMap::set_character_at(Coordinate coordinate, Character* character) {
    this->map[coordinate.get_y()][coordinate.get_x()] = character;
}

void CharacterMap::null_character_at(Coordinate coordinate) {
    std::cout << map[coordinate.get_y()][coordinate.get_x()];
    this->map[coordinate.get_y()][coordinate.get_x()] = nullptr;
}