// Created by Michael Ruiz on 2/19/20.
// Game.h - Main game loop and associated helper functions for the gameplay

#ifndef CIS29GROUP2GAME_GAME_H
#define CIS29GROUP2GAME_GAME_H


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
#include "CharacterMap.h"
#include "Selector.h"
#include "CoolText.h"
#include "Player.h"
#include "Exception.h"
#include "../Cursor.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 704
#define TEXTURE_SIZE 32
const std::string root_prefix = "./";    // Linux
const std::string map_texture_path = "share/maps/map_tiles32.png";
const std::string font_path = "share/resources/PressStart2P-Regular.ttf";
const std::string sidebar_font_path = "share/resources/ChunkyDunk.ttf";
const std::string sidebar_bg_path = "share/textures/sidebar_background.png";
const std::string cur_path = "share/sprites/cursor.png";
const std::string music_path = "./share/audio/BattleTheme.wav";

const unsigned int num_tiles_x = (WINDOW_WIDTH - (TEXTURE_SIZE * 8)) / TEXTURE_SIZE;
const unsigned int num_tiles_y = WINDOW_HEIGHT / TEXTURE_SIZE;

namespace tact {
    class Game;
}

class tact::Game {
private:
    sf::Music music;
    Cursor cur;
    Exception except;
    tact::VertexMap v_map;
    tact::CharacterMap c_map;
    sf::Event event;
    tact::Sidebar sidebar;
    tact::CoolText hit_text1;
	tact::CoolText hit_text2;
    tact::CoolText turn_text;
    tact::Player player1;
    tact::Player player2;
    tact::Selector selector;
    unsigned int move_frame;
    unsigned int iterator;
    bool unit_selected;
    bool unit_walking;
    bool menu_selected;
    bool move_selected;
    bool attack_selected;
    bool defend_selected;
    bool wait_selected;
    int turn_count;
public:
    Game();
    // Main game loop
    int play_game(sf::RenderWindow&);
    int set_iterator();
    int toggle_music();
    int swap_turns();
    tact::Player* get_current_player();
    tact::Player* get_enemy_player();
    int get_current_player_id();
    int get_enemy_player_id();
    int check_controllers();
    bool belongs_to_current_player(tact::Character*);
    void update_map();
    void move_cursor_key_poll();
    void adjust_volume_key_poll();
    void move_character_key_poll(sf::RenderWindow&);
    int menu_key_poll();
    void poll_key_logic(sf::RenderWindow&);
    int menu_joy_poll();
    void move_cursor_joy_poll();
    void poll_joy_logic(sf::RenderWindow&);
    void move_character_joy_poll(sf::RenderWindow&);
    void wait_character_poll();
    void defend_character_poll();
    void attack_character_joy_poll(sf::RenderWindow&);
    void attack_character_key_poll(sf::RenderWindow&);
	bool attack_character_rules(tact::Player* attackedP, tact::Character* attackerC, tact::Character* attackedC, int attackerPID, int attackedPID, sf::RenderWindow& window, tact::CoolText& hit_text);
    bool has_enemy_adjacent();
    bool belongs_to_enemy_player(tact::Character *character);
    void draw_units(sf::RenderWindow &window, tact::Player player);
    void set_menu_grey();
};


#endif //CIS29GROUP2GAME_GAME_H
