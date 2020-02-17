//
// Created by michael on 1/21/20.
//

#include "../../include/tact/VertexMap.h"
#include <iostream>
VertexMap::VertexMap() {
    tiles = {
            {69,48,39,5,0,0,0,0,0,0,0,0,7,46,46,46,69,259,69,69,69,69,69,69,69,69,69,69,69,69,39,39,39},
            {69,48,39,1,39,69,69,39,39,69,69,46,11,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,7,39,39,39},
            {69,48,39,1,39,39,39,39,39,39,39,39,39,39,39,39,39,259,39,39,39,39,127,128,128,129,39,39,1,39,39,39},
            {69,48,39,1,39,39,127,93,93,93,93,93,93,93,93,93,93,261,93,93,93,93,120,116,116,152,39,39,1,277,39,39},
            {69,48,39,1,39,39,150,116,116,151,116,116,116,96,139,139,116,116,139,139,116,116,116,151,116,152,39,39,8,279,39,39},
            {46,48,39,1,39,39,150,116,151,96,139,116,116,117,39,39,173,175,39,69,138,116,116,116,116,152,39,39,1,39,39,39},
            {46,48,39,1,39,39,173,174,174,175,39,138,116,140,39,39,39,47,47,48,39,173,174,174,174,175,39,39,1,39,39,69},
            {69,48,39,1,39,39,46,48,39,39,39,39,184,39,39,39,39,39,39,46,46,69,69,47,48,39,39,39,1,39,39,46},
            {69,48,39,8,39,69,69,46,47,48,39,39,29,39,39,39,39,47,47,47,48,39,39,39,39,39,39,39,1,39,39,39},
            {69,48,39,1,39,39,39,39,39,39,39,39,208,207,207,207,203,39,39,39,39,39,39,39,39,39,39,39,1,39,39,39},
            {69,48,39,1,39,39,46,69,46,47,48,39,39,47,48,39,208,207,203,39,39,39,39,39,5,0,0,0,13,39,39,46},
            {69,48,39,1,39,39,39,39,39,39,39,46,46,47,48,39,39,39,184,39,39,39,39,39,1,39,39,39,39,39,39,46},
            {46,39,39,1,39,39,39,39,39,39,39,39,39,5,0,0,0,0,29,0,0,0,0,0,13,39,46,46,47,48,39,46},
            {46,39,39,8,0,0,0,0,0,0,0,0,0,13,39,39,39,39,184,39,39,39,39,39,39,39,39,39,39,39,39,46},
            {46,39,39,1,39,39,69,69,48,69,48,39,39,39,39,39,39,39,208,207,207,203,39,39,39,46,46,46,48,39,39,39,39},
            {39,39,39,1,39,39,39,39,46,47,47,48,39,47,48,39,39,39,39,39,39,184,39,39,39,39,39,39,39,39,39,39},
            {39,39,39,1,39,47,48,39,39,46,47,47,47,48,39,39,39,39,39,39,39,184,39,39,127,128,129,39,46,46,39,39},
            {69,48,276,1,39,39,39,39,39,39,39,127,93,93,93,93,93,93,93,93,93,261,93,93,120,116,152,39,46,46,46,48},
            {69,48,278,13,39,39,39,39,39,39,39,150,116,151,116,116,116,116,116,116,116,116,116,116,116,174,175,39,39,39,39,39},
            {39,39,39,39,39,39,39,39,39,39,39,150,116,116,139,139,116,116,151,139,139,139,139,139,140,39,39,39,39,39,39,39},
            {39,39,39,39,39,39,39,69,39,39,69,173,174,175,39,39,138,116,140,39,39,39,69,69,48,39,46,69,69,48,39,69},
            {39,39,39,39,39,39,39,39,46,46,39,39,39,39,39,39,39,39,39,46,46,48,39,39,39,46,46,48,39,39,69,69}
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
        for (unsigned int y = 0; y < h; ++y)
        {
            /// get the current tile number
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
