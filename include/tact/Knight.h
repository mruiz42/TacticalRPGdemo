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
class Knight : public Sprite, public Character {
private:
    Character knight;
    int x_pos;
    int y_pos;
    
public:
    Knight(std::string s, int x, int y);
    
    

    
     
};


#endif //CIS29GROUP2GAME_KNIGHT_H
