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

class VertexMap : public sf::Drawable, public sf::Transformable {

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::Texture m_cursor_texture;
//    sf::Sprite m_cursor;
    std::vector<std::vector<int> > tiles;

public:
    VertexMap();
    bool loadMap(const std::string& tileset_img_path, const std::string& cur_img_path, sf::Vector2u tileSize,
                 const unsigned int w, const unsigned int h);


};


#endif //CIS29GROUP2GAME_VERTEXMAP_H
