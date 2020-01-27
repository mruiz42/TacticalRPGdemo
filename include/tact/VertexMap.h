//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_VERTEXMAP_H
#define CIS29GROUP2GAME_VERTEXMAP_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>

class VertexMap : public sf::Drawable, public sf::Transformable {
public:
    bool loadMap(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int w, unsigned int h);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};


#endif //CIS29GROUP2GAME_VERTEXMAP_H
