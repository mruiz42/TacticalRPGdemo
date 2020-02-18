//
// Created by michael on 2/17/20.
//

#include "../../include/tact/SpriteMap.h"

SpriteMap::SpriteMap(){
    for (int y = 0; y < 22; ++y){
        for (int x = 0; x < 32; ++x){
            map[y][x] = nullptr;
        }
    }

}

std::vector<std::vector<Character*> > SpriteMap::getSpritemap(){
    return this->map;
}