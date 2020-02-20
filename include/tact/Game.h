//
// Created by michael on 2/19/20.
//

#ifndef CIS29GROUP2GAME_GAME_H
#define CIS29GROUP2GAME_GAME_H

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 704
#define TEXTURE_SIZE 32

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Sidebar.h"
#include "VertexMap.h"
#include "Character.h"
#include "Cursor.h"
#include "CharacterMap.h"
#include <iostream>
const std::string root_prefix = "./";    // Linux
const std::string map_texture_path = "share/textures/map_tiles32.png";
const std::string font_path = "share/resources/PressStart2P-Regular.ttf";
const std::string sidebar_font_path = "share/resources/ChunkyDunk.ttf";
const std::string sidebar_bg_path = "share/textures/sidebar_background.png";
const std::string cur_path = "share/sprites/cursor.png";

class Game {
private:
    sf::Music music;
    Cursor cur;
    VertexMap v_map;
    CharacterMap c_map;
    sf::SoundBuffer buffer;
    sf::Event event;
    Sidebar sidebar;

public:
    Game();
    int play_game(sf::RenderWindow&);
    int toggle_music();

};


#endif //CIS29GROUP2GAME_GAME_H
