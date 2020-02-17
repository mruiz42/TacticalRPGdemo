//
// Created by michael on 1/21/20.
//

#include "../../include/tact/Knight.h"
#include<iostream>
Knight::Knight(int colorSelect)
{
    if (colorSelect == 1) //Purple Knight
    {
        if (!knight_texture.loadFromFile(FileNamePurple, sf::IntRect(0,15,32,32)))
        {
            std::cout << "Couldn't load " << FileNamePurple;
            exit(0);
        } 
    
        knight_sprite.setTexture(knight_texture);
        knight_sprite.setColor(sf::Color(255,255,255));
        
        knight_sprite_Negative_x.setTexture(knight_texture);
        knight_sprite_Negative_y.setTexture(knight_texture);
        knight_sprite_Postive_x.setTexture(knight_texture);
        knight_sprite_Postive_y.setTexture(knight_texture);

        knight_sprite_Postive_x.setColor(sf::Color(255,255,255,128));
        knight_sprite_Postive_y.setColor(sf::Color(255,255,255,128));
        knight_sprite_Negative_x.setColor(sf::Color(255,255,255,128));
        knight_sprite_Negative_y.setColor(sf::Color(255,255,255,128));

    }

    else if (colorSelect == 2) //Green Knight
    {

        if (!knight_texture.loadFromFile(FileNameGreen, sf::IntRect(232,15,32,32)))
        {
            std::cout << "Couldn't load " << FileNameGreen;
            exit(0);
        } 
    
        knight_sprite.setTexture(knight_texture);
        knight_sprite.setColor(sf::Color(255,255,255));

        knight_sprite_Negative_x.setTexture(knight_texture);
        knight_sprite_Negative_y.setTexture(knight_texture);
        knight_sprite_Postive_x.setTexture(knight_texture);
        knight_sprite_Postive_y.setTexture(knight_texture);

        knight_sprite_Postive_x.setColor(sf::Color(255,255,255,128));
        knight_sprite_Postive_y.setColor(sf::Color(255,255,255,128));
        knight_sprite_Negative_x.setColor(sf::Color(255,255,255,128));
        knight_sprite_Negative_y.setColor(sf::Color(255,255,255,128));
    }
    
    
}

Knight::Knight(std::string newName,unsigned int newLevel, unsigned int newExperience,
            unsigned int newHitPoints, unsigned int newManaPoints,unsigned int newAttack,unsigned int newDefense,
            unsigned int newSpeed, unsigned int newSpecialAttack, unsigned int newSpecialDefense)
{
    knight.set_name(newName);
    knight.set_level(newLevel);
    knight.set_experience(newExperience);
    knight.set_hit_points(newHitPoints);
    knight.set_mana_points(newManaPoints);
    knight.set_attack(newAttack);
    knight.set_defense(newDefense);
    knight.set_speed(newSpeed);
    knight.set_special_attack(newSpecialAttack);
    knight.set_special_defense(newSpecialDefense);
    if (!knight_texture.loadFromFile(FileNamePurple, sf::IntRect(0,0,32,32)))
    {
        std::cout << "Couldn't load " << FileNamePurple;
        exit(0);
    } 
}


sf::Sprite Knight :: returnSprite()
{
    return this->knight_sprite;
}

void Knight :: moveSprite(float x, float y)
{
    x*=32;
    y*=32;
    knight_sprite.move(sf::Vector2f(x,y));
}

void Knight ::resizeSprite(float x,float y)
{
    knight_sprite.setScale(sf::Vector2f(x,y));
}

void Knight::spriteFade()
{
    knight_sprite_Negative_x.move(sf::Vector2f(-32.f,0.f));
    knight_sprite_Negative_y.move(sf::Vector2f(0.f,-32.f));
    knight_sprite_Postive_x.move(sf::Vector2f(32.f,0.f));
    knight_sprite_Postive_y.move(sf::Vector2f(0.f,32.f));
   
}


void Knight::set(const sf::Vector2f & input)
{
    knight_sprite.setPosition(input);
    knight_sprite_Negative_x.setPosition(input);
    knight_sprite_Negative_y.setPosition(input);
    knight_sprite_Postive_x.setPosition(input);
    knight_sprite_Postive_y.setPosition(input);
}

sf::Sprite Knight:: return_Negative_x()
{
    return knight_sprite_Negative_x;
}

sf::Sprite Knight:: return_Negative_y()
{
    return knight_sprite_Negative_y;
}

sf::Sprite Knight:: return_Postive_x()
{
    return knight_sprite_Postive_x;
}

sf::Sprite Knight:: return_Postive_y()
{
    return knight_sprite_Postive_y;
}