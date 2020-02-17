//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_KNIGHT_H
#define CIS29GROUP2GAME_KNIGHT_H
#include "Character.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Sprite.h"
#include <string>
// Medium defense, medium attack
class Knight : public Character {
private:
    Character knight;
    std::string FileNamePurple = "./share/sprites/Game/newKnightPurple.png";
    std::string FileNameGreen = "./share/sprites/Game/newKnightGreen.png";
    sf::Texture knight_texture;
    sf::Sprite knight_sprite;
    sf::Sprite knight_sprite_Negative_y;
    sf::Sprite knight_sprite_Negative_x;
    sf::Sprite knight_sprite_Postive_x;
    sf::Sprite knight_sprite_Postive_y;
    public:
    Knight(int);
    Knight(std::string newName,unsigned int newLevel, unsigned int experience,
            unsigned int newHitPoints, unsigned int newManaPoints,unsigned int newAttack,unsigned int newDefense,
            unsigned int newSpeed, unsigned int newSpecialAttack, unsigned int newSpecialDefense);
    
    sf::Sprite returnSprite();
    void moveSprite(float,float);
    void resizeSprite(float,float);
    void spriteFade();
    

    void set(const sf::Vector2f&);
    sf::Sprite return_Negative_x();
    sf::Sprite return_Negative_y();
    sf::Sprite return_Postive_x();
    sf::Sprite return_Postive_y();    
};


#endif //CIS29GROUP2GAME_KNIGHT_H
