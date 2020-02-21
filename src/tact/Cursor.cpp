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
    this->x = (this->sprite.getPosition().x);
    this->y = (this->sprite.getPosition().y);
}

Coordinate Cursor::get_tile_coordinate(){
    Coordinate temp;
    temp.set_x(this->x / 32);
    temp.set_y(this->y / 32);
    return temp;
}

void Cursor::jump_to(float x, float y) {
    y *= 32;
    x *= 32;
    this->sprite.setPosition(x, y);
}

std::ostream& operator<< (std::ostream& out, const Cursor& cursor){
    out << "(" + std::to_string(cursor.x/32) + "," + std::to_string(cursor.y/32) + ")" << std::endl;
    return out;
}