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
const std::string fontFileName = "share/resources/PressStart2P-Regular.ttf";
const std::string root_path = "./";    // Linux

class Game {
public:
    int play(sf::RenderWindow&);
private:

};


#endif //CIS29GROUP2GAME_GAME_H
