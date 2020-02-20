//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Cursor.h"

Cursor::Cursor(){
    if (!texture.loadFromFile(cur_path, sf::IntRect(0,0,32,32)))
    {
        std::cerr << "Couldn't load sprite:" << cur_path;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
    this->xy.x = 0;
    this->xy.y = 0;
}
Cursor::Cursor(int x, int y) {
    if (!texture.loadFromFile(cur_path, sf::IntRect(0,0,32,32)))
    {
        std::cerr << "Couldn't load sprite:" << cur_path;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
    this->xy.x = x;
    this->xy.y = y;
}

void Cursor::moveSprite(float x, float y)
{
    this->sprite.move(sf::Vector2f(x,y));
    this->xy.x = this->sprite.getPosition().x;
    this->xy.y = this->sprite.getPosition().y;
}