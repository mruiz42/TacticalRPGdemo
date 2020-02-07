//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_SPRITE_H
#define CIS29GROUP2GAME_SPRITE_H
#include <SFML/Graphics/Sprite.hpp>

class Sprite {

private:
    sf::Sprite sprite;
public:
    sf::Sprite returnSprite();
    void moveSprite(float x, float y);
};


#endif //CIS29GROUP2GAME_SPRITE_H
