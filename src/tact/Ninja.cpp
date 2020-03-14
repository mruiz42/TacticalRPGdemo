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

using namespace tact;

Ninja::Ninja() : Character() {
    try {
        if (!texture.loadFromFile(ninja_spritesheet_path)){
            throw(ninja_spritesheet_path);
        }
    }
    catch(const std::string& error){
        std::cout << "Could not load " <<  error << " from file." << std::endl;
    }
    sidebar_sprite.setTexture(texture);
	charFace1.setTexture(texture);
    charFace1.setTextureRect(sf::IntRect(8,400,64,87));
	charFace2.setTexture(texture);
    charFace2.setTextureRect(sf::IntRect(272,400,64,87));
    map_sprite.setTexture(texture);
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));
    this->name = "Ninja";
    this->level = 10;
    this->experience = 0;
    this->hit_points = 800;
    this->mana_points = 625;
    this->attack = 28;
    this->defense = 20;
    this->speed = 39;
    this->special_attack = 23;
    this->special_defense = 26;
}

Ninja::Ninja(int x, int y) : Character(x, y) {
    try {
        if (!texture.loadFromFile(ninja_spritesheet_path)){
            throw(ninja_spritesheet_path);
        }
    }
    catch(const std::string& error){
        std::cout << "Could not load " <<  error << " from file." << std::endl;
    }
    sidebar_sprite.setTexture(texture);
	charFace1.setTexture(texture);
    charFace1.setTextureRect(sf::IntRect(8,400,64,87));
	charFace2.setTexture(texture);
    charFace2.setTextureRect(sf::IntRect(272,400,64,87));
    map_sprite.setTexture(texture);
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));
    this->name = "Ninja";
    this->level = 1;
    this->experience = 0;
    this->hit_points = 800;
    this->mana_points = 625;
    this->attack = 28;
    this->defense = 20;
    this->speed = 39;
    this->special_attack = 23;
    this->special_defense = 26;
}

