//
// Created by michael on 2/17/20.
//

#ifndef CIS29GROUP2GAME_CHARACTERMAP_H
#define CIS29GROUP2GAME_CHARACTERMAP_H
#include <vector>
#include "Character.h"

class CharacterMap : public sf::Drawable, public sf::Transformable{
private:
    std::vector<std::vector<Character*> > map;
public:
    CharacterMap();
    ~CharacterMap();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::vector<std::vector<Character*> > getSpritemap();
};


#endif //CIS29GROUP2GAME_CHARACTERMAP_H
