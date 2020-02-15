//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_SIDEBAR_H
#define CIS29GROUP2GAME_SIDEBAR_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
// we wanna display character picture, name, hp, mp, (stats?) then user options
class Sidebar : public sf::Drawable, public sf::Transformable {
private:
    sf::Texture sidebar_background;
    sf::Sprite sidebar;

public:
    Sidebar(std::string);
    sf::Texture getBackground() const { return this->sidebar_background; }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //CIS29GROUP2GAME_SIDEBAR_H
