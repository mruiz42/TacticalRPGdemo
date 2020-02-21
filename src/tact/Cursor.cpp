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
    this->x = (this->sprite.getPosition().x/TEXTURE_SIZE);
    this->y = (this->sprite.getPosition().y/TEXTURE_SIZE);
}

Coordinate Cursor::get_tile_coordinate(){
    Coordinate temp;
    temp.set_x(this->x / TEXTURE_SIZE);
    temp.set_y(this->y / TEXTURE_SIZE);
    return temp;
}

void Cursor::jump_to(int x, int y) {
    this->set_coordinate(x, y);
    float yf = y * TEXTURE_SIZE;
    float xf = x * TEXTURE_SIZE;
    this->sprite.setPosition(xf, yf);
}

std::ostream& operator<< (std::ostream& out, const Cursor& cursor){
    out << "(" + std::to_string(cursor.get_x()) + "," + std::to_string(cursor.get_y()) + ")" << std::endl;
    return out;
}