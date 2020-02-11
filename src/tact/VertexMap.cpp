//
// Created by michael on 1/21/20.
//

#include "../../include/tact/VertexMap.h"
#include <iostream>
VertexMap::VertexMap() {
    tiles = {
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}
    };
}
// something
bool VertexMap::loadMap(const std::string& tileset_img_path, const std::string& cur_img_path,
                        sf::Vector2u tileSize, const unsigned int w, const unsigned int h) {
    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset_img_path))
        return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(w * h * 4);


    // populate the vertex array, with one quad per tile
    for (unsigned int x = 0; x < w; ++x)
        for (unsigned int y = 0; y < h; ++y) {
            // get the current tile number
            int tileNumber = tiles[y][x];
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(x + y * w) * 4];
            // define the top, bottom, left, and right of the tiles on the screen
            int left = x * tileSize.x;
            int right = left + tileSize.x;
            int top = y * tileSize.y;
            int bottom = top + tileSize.y;
            quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
            quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
            quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);
            // define top, bottom, left, and right of the tile on the texture
            int texLeft = tu * (tileSize.x+2);
            int texRight = texLeft + tileSize.x;
            int texTop = tv * (tileSize.y+2);
            int texBottom = texTop + tileSize.y;

            //quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            //quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            //quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            //quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(texLeft, texTop);
            quad[1].texCoords = sf::Vector2f(texRight, texTop);
            quad[2].texCoords = sf::Vector2f(texRight, texBottom);
            quad[3].texCoords = sf::Vector2f(texLeft, texBottom);
            }
    // load cursor
    if (!m_cursor_texture.loadFromFile(cur_img_path, sf::IntRect(0,0,32,32))) {
        return false;
    }



        return true;
    }

    

    void VertexMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // apply the transform
        states.transform *= getTransform();
        // apply the tileset texture
        states.texture = &m_tileset;
        // draw the vertex array
        target.draw(m_vertices, states);
        target.draw(m_cursor, states);

    }