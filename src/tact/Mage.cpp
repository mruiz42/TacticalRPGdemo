//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Mage.h"

using namespace tact;

Mage::Mage() : Character() {
    if (!texture.loadFromFile(mage_spritesheet_path)){
        std::cout << "Error: " + mage_spritesheet_path + " could not be loaded." << std::endl;
    }
    sidebar_sprite.setTexture(texture);
	charFace1.setTexture(texture);
    charFace1.setTextureRect(sf::IntRect(8,406,84,100));
	charFace2.setTexture(texture);
    charFace2.setTextureRect(sf::IntRect(272,405,84,100));
    map_sprite.setTexture(texture);
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));
    this->name = "Mage";
    this->level = 10;
    this->experience = 0;
    this->hit_points = 550;
    this->mana_points = 427;
    this->attack = 16;
    this->defense = 23;
    this->speed = 21;
    this->special_attack = 56;
    this->special_defense = 67;
}

Mage::Mage(int x, int y) : Character(x, y) {
    if (!texture.loadFromFile(mage_spritesheet_path)){
        std::cout << "Error: " + mage_spritesheet_path + " could not be loaded." << std::endl;
    }
    sidebar_sprite.setTexture(texture);
	charFace1.setTexture(texture);
    charFace1.setTextureRect(sf::IntRect(8,406,84,100));
	charFace2.setTexture(texture);
    charFace2.setTextureRect(sf::IntRect(272,405,84,100));
    map_sprite.setTexture(texture);
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));
    this->name = "Mage";
    this->level = 10;
    this->experience = 0;
    this->hit_points = 20; //550
    this->mana_points = 427;
    this->attack = 16;
    this->defense = 23;
    this->speed = 21;
    this->special_attack = 56;
    this->special_defense = 67;
}

Mage::~Mage() {
	std::cout << "Mage dtor called.\n"; 
}