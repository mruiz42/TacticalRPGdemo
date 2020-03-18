//
// Created by michael on 2/7/20.
//

#ifndef CIS29GROUP2GAME_SPRITE_H
#define CIS29GROUP2GAME_SPRITE_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace tact {
    class Sprite;
}

class tact::Sprite {

protected:
    std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Sprite();
    Sprite(std::string);
    std::string get_filename();
    sf::Texture get_texture();
    sf::Sprite& get_sprite();

    void set_filename(std::string&);
    void set_texture(sf::Texture&);
    void set_sprite(sf::Sprite&);
    void moveSprite(float x, float y);
};


#endif //CIS29GROUP2GAME_SPRITE_H
