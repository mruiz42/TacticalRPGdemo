//
// Created by michael on 2/19/20.
//

#ifndef CIS29GROUP2GAME_GAME_H
#define CIS29GROUP2GAME_GAME_H

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 704

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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Sidebar.h"
#include "VertexMap.h"
#include "Character.h"
#include "Cursor.h"
#include "CharacterMap.h"
#include "Selector.h"
#include "Player.h"


const std::string root_prefix = "./";    // Linux
const std::string map_texture_path = "share/textures/map_tiles32.png";
const std::string font_path = "share/resources/PressStart2P-Regular.ttf";
const std::string sidebar_font_path = "share/resources/ChunkyDunk.ttf";
const std::string sidebar_bg_path = "share/textures/sidebar_background.png";
const std::string vol_change_sound_path = "share/audio/volume_change.wav";
const unsigned int num_tiles_x = (WINDOW_WIDTH - (TEXTURE_SIZE * 8)) / TEXTURE_SIZE;
const unsigned int num_tiles_y = WINDOW_HEIGHT / TEXTURE_SIZE;
const unsigned int num_tiles_total = num_tiles_x * num_tiles_y;

class Game {
private:
    sf::Music music;
    Cursor cur;
    VertexMap v_map;
    CharacterMap c_map;
    sf::Sound sound;
    sf::SoundBuffer buffer;
    sf::Event event;
    Sidebar sidebar;
    Player player1;
    Player player2;
    Selector selector;
    unsigned int iterator;
    bool unit_selected;
    bool menu_selected;
    bool move_selected;
    bool attack_selected;
    bool defend_selected;
    bool wait_selected;

    int turn_count;
public:
    Game();
    int play_game(sf::RenderWindow&);
    int set_iterator();
    int toggle_music();
    int swap_turns();
    Player& get_current_player();
    Player& get_enemy_player();
    int get_current_player_id();
    int get_enemy_player_id();
    int check_controllers();
    bool belongs_to_current_player(Character*);
    void update_map();
    void set_framerate();
    void move_cursor_key_poll();
    void adjust_volume_key_poll();
    void move_character_key_poll();
    int menu_key_poll();

    void poll_key_logic();

    int menu_joy_poll();

    int move_cursor_joy_poll();

    void poll_joy_logic();

    void move_character_joy_poll();

    void wait_character_poll();

    void defend_character_poll();

    void attack_character_key_poll();
	void attack_character_rules(Player &attackedP, Character &attackerC, Character &attackedC, int attackedPID);

    bool has_enemy_adjacent();

    bool belongs_to_enemy_player(Character *character);
};


#endif //CIS29GROUP2GAME_GAME_H
