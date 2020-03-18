//
// Created by michael on 2/7/20.
//

#include "../include/Cursor.h"

Cursor::Cursor() : Coordinate(0, 0) {
    if (!texture.loadFromFile(cur_path, sf::IntRect(0,0,texture_size,texture_size))) {
        std::cerr << "Couldn't load sprite:" << cur_path;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
}

Cursor::Cursor(int x, int y) : Coordinate (x, y) { }

Cursor::Cursor(int x, int y, int texture_size) : Coordinate (x,y), texture_size(texture_size) { }

Cursor::Cursor(std::string cur_path) : Coordinate(0,0){
    if (!texture.loadFromFile(cur_path, sf::IntRect(0,0,texture_size,texture_size))) {
        std::cerr << "Couldn't load sprite:" << cur_path;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
}

Cursor::Cursor(int x, int y, std::string cur_path) : Coordinate(x,y) {
    if (!texture.loadFromFile(cur_path, sf::IntRect(0,0,texture_size,texture_size))) {
        std::cerr << "Couldn't load sprite:" << cur_path;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
}

Cursor::Cursor(int x, int y, int tile_size, std::string cur_path) : Coordinate(x, y), texture_size(texture_size) {
    if (!texture.loadFromFile(cur_path, sf::IntRect(0,0,texture_size,texture_size))) {
        std::cerr << "Couldn't load sprite:" << cur_path;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
}

void Cursor::moveSprite(float x, float y) {
    this->sprite.move(sf::Vector2f(x,y));
    this->x = (this->sprite.getPosition().x/texture_size);
    this->y = (this->sprite.getPosition().y/texture_size);
}

Coordinate Cursor::get_tile_coordinate(){
    Coordinate temp;
    temp.set_x(this->x / texture_size);
    temp.set_y(this->y / texture_size);
    return temp;
}

void Cursor::jump_to(int x, int y) {
    this->set_coordinate(x, y);
    float yf = y * texture_size;
    float xf = x * texture_size;
    this->sprite.setPosition(xf, yf);
}

void Cursor::jump_to(Coordinate coordinate) {
    this->set_coordinate(coordinate);
    float yf = this->get_y() * texture_size;
    float xf = this->get_x() * texture_size;
    this->sprite.setPosition(xf,yf);
}

std::ostream& operator<< (std::ostream& out, const Cursor& cursor){
    out << "(" + std::to_string(cursor.get_x()) + "," + std::to_string(cursor.get_y()) + ")" << std::endl;
    return out;
}

int Cursor::load_texture() {
    if (!texture.loadFromFile(this->cur_path, sf::IntRect(0,0,texture_size,texture_size))) {
        std::cerr << "Couldn't load sprite:" << cur_path;
        exit(1);
    }
    this->sprite.setTexture(this->texture);
    return 0;
}