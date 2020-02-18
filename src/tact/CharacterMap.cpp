//
// Created by michael on 2/17/20.
//

#include "../../include/tact/CharacterMap.h"
#include "../../include/tact/Ninja.h"

CharacterMap::CharacterMap(){
    map.resize(22);
    for (int y = 0; y < 22; ++y){
        for (int x = 0; x < 32; ++x){
            map[y].push_back(nullptr);
        }
    }
    map[1][1] = new Ninja("share/sprites/ninja.png");

}
CharacterMap::~CharacterMap() {
    for (int y = 0; y < 22; ++y){
        for (int x = 0; x < 32; ++x) {
            if (map[y][x] != nullptr){
                delete map[y][x];
            }
        }
    }
}
std::vector<std::vector<Character*> > CharacterMap::getSpritemap(){
    return this->map;
}

void CharacterMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();
    // apply the tileset texture
    states.texture = map[1][1]->;
    // draw the vertex array
    target.draw(m_vertices, states);

}