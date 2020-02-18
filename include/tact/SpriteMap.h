//
// Created by michael on 2/17/20.
//

#ifndef CIS29GROUP2GAME_SPRITEMAP_H
#define CIS29GROUP2GAME_SPRITEMAP_H
#include <vector>
#include "Character.h"

class SpriteMap {
private:
    std::vector<std::vector<Character*> > map;
public:
    SpriteMap();
    std::vector<std::vector<Character*> > getSpritemap();
};


#endif //CIS29GROUP2GAME_SPRITEMAP_H
