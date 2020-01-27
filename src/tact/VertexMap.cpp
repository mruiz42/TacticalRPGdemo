//
// Created by michael on 1/21/20.
//

#include "../../include/tact/VertexMap.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>

bool VertexMap::loadMap(const std::string& tileset, sf::Vector2u tileSize, const int* tiles,
        unsigned int w, unsigned int h) {
// load the tileset texture
if (!m_tileset.loadFromFile(tileset))
return false;

// resize the vertex array to fit the level size
m_vertices.setPrimitiveType(sf::Quads);
m_vertices.resize(w * h * 4);


// populate the vertex array, with one quad per tile
for (unsigned int i = 0; i < w; ++i)
for (unsigned int j = 0; j < h; ++j)
{
// get the current tile number
int tileNumber = tiles[i + j * w];

//                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
//                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
// find its position in the tileset texture
int tu = tileNumber % 15;
int tv = tileNumber / 15;

// get a pointer to the current tile's quad
sf::Vertex* quad = &m_vertices[(i + j * w) * 4];

// define the top, bottom, left, and right of the tiles on the screen
int left = i * tileSize.x;
int right = left + tileSize.x;
int top = j * tileSize.y;
int bottom = top + tileSize.y;

//                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
//                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
//                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
//                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
// define its 4 corners
quad[0].position = sf::Vector2f(left, top);
quad[1].position = sf::Vector2f(right, top);
quad[2].position = sf::Vector2f(right, bottom);
quad[3].position = sf::Vector2f(left, bottom);

// define top, bottom, left, and right of the tile on the texture
int texLeft = tu * (tileSize.x+1);
int texRight = texLeft + tileSize.x;
int texTop = tv * (tileSize.y+1);
int texBottom = texTop + tileSize.y;

//                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
//                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
//                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
//                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
// define its 4 texture coordinates
quad[0].texCoords = sf::Vector2f(texLeft, texTop);
quad[1].texCoords = sf::Vector2f(texRight, texTop);
quad[2].texCoords = sf::Vector2f(texRight, texBottom);
quad[3].texCoords = sf::Vector2f(texLeft, texBottom);
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
}
