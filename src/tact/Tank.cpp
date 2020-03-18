//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Tank.h"
using namespace tact;

Tank::Tank() : Character() {
    if (!texture.loadFromFile(tank_spritesheet_path)){
        std::cout << "Error: " + tank_spritesheet_path + " could not be loaded." << std::endl;
    }
    sidebar_sprite.setTexture(texture);
	character_Face1.setTexture(texture);
    character_Face1.setTextureRect(sf::IntRect(8,406,84,100));
	character_Face2.setTexture(texture);
    character_Face2.setTextureRect(sf::IntRect(272,405,84,100));
    map_sprite.setTexture(texture);
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));
    this->name = "Tank";
    this->level = 19;
    this->experience = 0;
    this->hit_points = 220;
    this->mana_points = 23;
    this->attack = 30;
    this->defense = 38;
    this->speed = 21;
    this->special_attack = 27;
    this->special_defense = 101;
}

Tank::Tank(int x, int y) : Character(x, y) {
    if (!texture.loadFromFile(tank_spritesheet_path)){
        std::cout << "Error: " + tank_spritesheet_path + " could not be loaded." << std::endl;
    }
    sidebar_sprite.setTexture(texture);
	character_Face1.setTexture(texture);
    character_Face1.setTextureRect(sf::IntRect(8,406,84,100));
	character_Face2.setTexture(texture);
    character_Face2.setTextureRect(sf::IntRect(272,405,84,100));
    map_sprite.setTexture(texture);
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));
    this->name = "Tank";
    this->level = 19;
    this->experience = 0;
    this->hit_points = 220;
    this->mana_points = 23;
    this->attack = 30;
    this->defense = 38;
    this->speed = 21;
    this->special_attack = 27;
    this->special_defense = 101;
}

Tank::~Tank() {
	std::cout << "Tank dtor called.\n"; 
}