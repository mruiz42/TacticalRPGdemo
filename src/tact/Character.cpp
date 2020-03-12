//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Character.h"
#include <SFML/Audio/SoundBuffer.hpp>

using namespace tact;

Character::Character() : xy(0,0) {
    name = "";
    level = 0;
    attack_on = false;
    moved = false;
    defending = false;
    walking = false;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
    walk_animation[0] = 0;
    walk_animation[1] =10;
    textureRect = sf::IntRect(1,13,32,32);
}

Character::Character(Coordinate xy) : xy(xy) {
    name = "";
    level = 0;
    attack_on = false;
    moved = false;
    defending = false;
    walking = false;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
    walk_animation[0] = 0;
    walk_animation[1] =10;
    textureRect = sf::IntRect(1,13,32,32);

}

Character::Character(int x, int y) : xy(x, y){
    name = "";
    level = 0;
    attack_on = false;
    moved = false;
    defending = false;
    walking = false;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
    textureRect = sf::IntRect(1,13,32,32);
    walk_animation[0] = 0;
    walk_animation[1] =10;
}

Character::Character(std::string filename){
    texture.loadFromFile(filename);
    sidebar_sprite.setTexture(texture);
    map_sprite.setTexture(texture);
    textureRect = sf::IntRect(1,13,32,32);
    name = "";
    attack_on = false;
    moved = false;
    defending = false;
    walking = false;
    level = 0;
    experience = 0;
    hit_points = 0;
    mana_points = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    special_attack = 0;
    special_defense = 0;
    walk_animation[0] = 0;
    walk_animation[1] =10;

}

void Character::set_coordinate(int x, int y) {
    this->xy.set_x(x);
    this->xy.set_y(y);
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->map_sprite, states);
}

void Character::play_voice() {
    voice.play();
}

void Character::flip_sprite() {
//    this->map_sprite.setOrigin()
}
void Character::walk()
{
    walk_animation[0]++;
    if(walk_animation[0]==walk_animation[1])
    {
        if(textureRect == sf::IntRect(100,13,32,32))
        {
            textureRect = sf::IntRect(67,13,32,32);
        }

        else
        {
            textureRect.left += 33;
        }
        map_sprite.setTextureRect(textureRect);
        walk_animation[0]=0;
    }
}

void Character::reset_pos()
{
    map_sprite.setTextureRect(sf::IntRect(1,13,32,32));
}

void Character::flip_map_sprite() {
    this->get_map_sprite().setScale({-1,1});

}