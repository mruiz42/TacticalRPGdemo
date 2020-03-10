//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Knight.h"
#include<iostream>

using namespace tact;

//Knight::Knight() {
//    knight_sprite.setTexture(knight_texture);
//    knight_sprite.setColor(sf::Color(255,255,255));
//    //knight_sprite.move(sf::Vector2f(100.f,100.f));
//
//}
//
//Knight::Knight(std::string newName,unsigned int newLevel, unsigned int newExperience,
//            unsigned int newHitPoints, unsigned int newManaPoints,unsigned int newAttack,unsigned int newDefense,
//            unsigned int newSpeed, unsigned int newSpecialAttack, unsigned int newSpecialDefense)
//{
//    knight.set_name(newName);
//    knight.set_level(newLevel);
//    knight.set_experience(newExperience);
//    knight.set_hit_points(newHitPoints);
//    knight.set_mana_points(newManaPoints);
//    knight.set_attack(newAttack);
//    knight.set_defense(newDefense);
//    knight.set_speed(newSpeed);
//    knight.set_special_attack(newSpecialAttack);
//    knight.set_special_defense(newSpecialDefense);
//    if (!knight_texture.loadFromFile(FileName, sf::IntRect(0,0,32,32)))
//    {
//        std::cout << "Couldn't load " << FileName;
//        exit(0);
//    }
//}

sf::Sprite Knight :: returnSprite()
{
    return knight_sprite;
}

void Knight :: moveSprite(float x, float y)
{
    knight_sprite.move(sf::Vector2f(x,y));
}
