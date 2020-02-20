//
// Created by michael on 1/21/20.
//
/*    unsigned int level;
    unsigned int experience;
    unsigned int hit_points;
    unsigned int mana_points;
    unsigned int attack;
    unsigned int defense;
    unsigned int speed;
    unsigned int special_attack;
    unsigned int special_defense;*/

#include "../../include/tact/Ninja.h"

Ninja::Ninja() : Character() {
    if (!texture.loadFromFile(ninja_spritesheet_path)){
        std::cout << "Error: " + ninja_spritesheet_path + " could not be loaded." << std::endl;
    }
    sidebar_sprite.setTexture(texture);
    map_sprite.setTexture(texture);
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));
    this->name = "Ninja";
    this->level = 1;
    this->experience = 0;
    this->hit_points = 100;
    this->mana_points = 25;
    this->attack = 28;
    this->defense = 20;
    this->speed = 39;
    this->special_attack = 23;
    this->special_defense = 26;
}

Ninja::Ninja(int x, int y) : Character(x, y) {
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));
    this->name = "Ninja";
    this->level = 1;
    this->experience = 0;
    this->hit_points = 100;
    this->mana_points = 25;
    this->attack = 28;
    this->defense = 20;
    this->speed = 39;
    this->special_attack = 23;
    this->special_defense = 26;
}