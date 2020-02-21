//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Cursor.h"

Cursor::Cursor() : Coordinate(0, 0) {
    if (!texture.loadFromFile(cur_path, sf::IntRect(0,0,32,32))) {
        std::cerr << "Couldn't load sprite:" << cur_path;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
}
Cursor::Cursor(int x, int y) : Coordinate (x, y) {
    if (!texture.loadFromFile(cur_path, sf::IntRect(0,0,32,32))) {
        std::cerr << "Couldn't load sprite:" << cur_path;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
}

void Cursor::moveSprite(float x, float y) {
    this->sprite.move(sf::Vector2f(x,y));
    this->set_x(this->sprite.getPosition().x);
    this->set_y(this->sprite.getPosition().y);
}

void Cursor::jump_to(float x, float y) {
    y *= 32;
    x *= 32;
    this->sprite.setPosition(x, y);
}