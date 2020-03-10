//
// Created by michael on 2/17/20.
//

#ifndef CIS29GROUP2GAME_CHARACTERMAP_H
#define CIS29GROUP2GAME_CHARACTERMAP_H
#include <vector>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Character.h"

namespace tact {
    class CharacterMap;
}

class CharacterMap : public sf::Drawable, public sf::Transformable {
private:
//    sf::VertexArray m_vertices;
    std::vector<std::vector<Character*> > map;
public:
    CharacterMap();
    ~CharacterMap();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::vector<std::vector<Character*> >& get_map();
    Character* get_character_at(int, int);
    Character* get_character_at(Coordinate coordinate);
    Character& get_character_address_at(Coordinate coordinate);
    void null_character_at(Coordinate coordinate);

    void set_character_at(Coordinate coordinate, Character*);
};


#endif //CIS29GROUP2GAME_CHARACTERMAP_H
