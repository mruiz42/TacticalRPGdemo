//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Sprite.h"
sf::Sprite Sprite::returnSprite()
{
    return this->sprite;
}

void Sprite::moveSprite(float x, float y)
{
    sprite.move(sf::Vector2f(x,y));
}