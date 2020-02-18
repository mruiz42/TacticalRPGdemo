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
    sf::Sprite sprite_Negative_y;
    sf::Sprite sprite_Negative_x;
    sf::Sprite sprite_Positive_x;
    sf::Sprite sprite_Positive_y;
public:
    Sprite(std::string);
    sf::Sprite getSprite();
    void moveSprite(float x, float y);
    void spriteFade();
    void set(const sf::Vector2f&);
    
    sf::Sprite return_Negative_x();
    sf::Sprite return_Negative_y();
    sf::Sprite return_Postive_x();
    sf::Sprite return_Postive_y();    
};


#endif //CIS29GROUP2GAME_SPRITE_H
