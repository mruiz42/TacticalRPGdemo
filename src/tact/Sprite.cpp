//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Sprite.h"
#include <iostream>
Sprite::Sprite (std::string s) {
    if (!texture.loadFromFile(s, sf::IntRect(0,0,32,32)))
    {
        std::cerr << "Couldn't load sprite:" << filename;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
    this->sprite_Negative_x.setTexture(this->texture);
    this->sprite_Negative_y.setTexture(this->texture);
    this->sprite_Positive_x.setTexture(this->texture);
    this->sprite_Positive_y.setTexture(this->texture);


}

sf::Sprite Sprite::getSprite()
{
    return this->sprite;
}

void Sprite::moveSprite(float x, float y)
{
    sprite.move(sf::Vector2f(x,y));
}

sf::Sprite Sprite:: return_Negative_x()
{
    return sprite_Negative_x;
}

sf::Sprite Sprite:: return_Negative_y()
{
    return sprite_Negative_y;
}

sf::Sprite Sprite:: return_Postive_x()
{
    return sprite_Positive_x;
}

sf::Sprite Sprite:: return_Postive_y()
{
    return sprite_Positive_y;
}

void Sprite::spriteFade()
{
    sprite_Negative_x.move(sf::Vector2f(-32.f,0.f));
    sprite_Negative_y.move(sf::Vector2f(0.f,-32.f));
    sprite_Positive_x.move(sf::Vector2f(32.f,0.f));
    sprite_Positive_y.move(sf::Vector2f(0.f,32.f));
   
}

void Sprite::set(const sf::Vector2f & input)
{
    sprite.setPosition(input);
    sprite_Negative_x.setPosition(input);
    sprite_Negative_y.setPosition(input);
    sprite_Positive_x.setPosition(input);
    sprite_Positive_y.setPosition(input);
}