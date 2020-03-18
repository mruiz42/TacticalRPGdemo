//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Sprite.h"
#include <iostream>

using namespace tact;

Sprite::Sprite (std::string s) {
    try{
        if (!texture.loadFromFile(s, sf::IntRect(0,0,32,32))){
            throw(filename);
        }
    }
    catch(const std::string& error){
        std::cout << "Could not load " <<  error << " from file." << std::endl;
    }
    this->sprite.setTexture(this->texture);
}

sf::Texture Sprite::get_texture() {
    return this->texture;
}

sf::Sprite& Sprite::get_sprite(){
    return this->sprite;
}

void Sprite::set_filename(std::string& filename) {
    this->filename = filename;
}
void Sprite::set_texture(sf::Texture& texture) {
    this->texture = texture;
}
void Sprite::set_sprite(sf::Sprite& sprite) {
    this->sprite = sprite;
}

void Sprite::moveSprite(float x, float y){
    sprite.move(sf::Vector2f(x,y));
}