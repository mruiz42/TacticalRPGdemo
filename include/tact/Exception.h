//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_EXCEPTION_H
#define CIS29GROUP2GAME_EXCEPTION_H


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>

const std::string exception_path = "./share/resources/ChunkyDunk.ttf";

class Exception : public sf::Drawable, public sf::Transformable
{
private:
   sf::Text text;
   sf::Font font;
public:
    Exception();
    sf::Text return_Text();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void show_except();
    void hide_expect();
    void shift(sf::Vector2f);
};


#endif //CIS29GROUP2GAME_CURSOR_H
