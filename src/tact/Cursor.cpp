//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Cursor.h"

Cursor::Cursor(std::string s, int x, int y) : Sprite(s) {
    this->x_pos = x;
    this->y_pos = y;
}

void Cursor::moveSprite(float x, float y)
{
    this->sprite.move(sf::Vector2f(x,y));
    this->x_pos = this->sprite.getPosition().x;
    this->y_pos = this->sprite.getPosition().y;
}