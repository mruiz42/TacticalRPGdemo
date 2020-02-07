//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_SPRITE_H
#define CIS29GROUP2GAME_SPRITE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

class Sprite {

protected:
    std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Sprite(std::string);
    sf::Sprite returnSprite();
    void moveSprite(float x, float y);
};


#endif //CIS29GROUP2GAME_SPRITE_H
