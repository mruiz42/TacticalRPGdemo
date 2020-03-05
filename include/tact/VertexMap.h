//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_VERTEXMAP_H
#define CIS29GROUP2GAME_VERTEXMAP_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>
#include "Coordinate.h"

class VertexMap : public sf::Drawable, public sf::Transformable {

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    std::vector<std::vector<int> > map;

public:
    VertexMap();
    bool loadMap(const std::string&, const std::string&, sf::Vector2u, const unsigned int, const unsigned int);
    int get_type_at(int, int) const;
    int get_type_at(Coordinate xy) const;
};


#endif //CIS29GROUP2GAME_VERTEXMAP_H
