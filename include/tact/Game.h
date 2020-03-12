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
#include "Sidebar.h"
#include "VertexMap.h"
#include "Character.h"
#include "Cursor.h"
#include "CharacterMap.h"
#include "Selector.h"
#include "CoolText.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

const std::string root_prefix = "./";    // Linux
const std::string map_texture_path = "share/textures/map_tiles32.png";
const std::string font_path = "share/resources/PressStart2P-Regular.ttf";
const std::string sidebar_font_path = "share/resources/ChunkyDunk.ttf";
const std::string battleLog_font_path = "share/resources/arial.ttf";
const std::string sidebar_bg_path = "share/textures/sidebar_background.png";
const std::string vol_change_sound_path = "share/audio/volume_change.wav";

const unsigned int num_tiles_x = (WINDOW_WIDTH - (TEXTURE_SIZE * 8)) / TEXTURE_SIZE;
const unsigned int num_tiles_y = WINDOW_HEIGHT / TEXTURE_SIZE;
const unsigned int num_tiles_total = num_tiles_x * num_tiles_y;

namespace tact {
    class Game;
}
class tact::Game {
private:
    sf::Music music;
    Cursor cur;
    tact::VertexMap v_map;
    tact::CharacterMap c_map;
    sf::Sound sound;
    sf::SoundBuffer buffer;
    sf::Event event;
    tact::Sidebar sidebar;
    tact::CoolText hit_text;
    tact::CoolText turn_text;
    tact::Player player1;
    tact::Player player2;
    tact::Selector selector;
    unsigned int move_frame;
    unsigned int iterator;
    bool game_end;
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
    void set_framerate();
    void move_cursor_key_poll();
    void adjust_volume_key_poll();
    void move_character_key_poll(sf::RenderWindow&);
    int menu_key_poll();
    void poll_key_logic(sf::RenderWindow& window);
    int menu_joy_poll();
    void move_cursor_joy_poll();
    void poll_joy_logic();
    void move_character_joy_poll();
    void wait_character_poll();
    void defend_character_poll();
    void attack_character_key_poll(sf::RenderWindow& window);
	void attack_character_rules(tact::Player* attackedP, tact::Character* attackerC, tact::Character* attackedC, int attackerPID,
	        int attackedPID, sf::RenderWindow& window);
    bool has_enemy_adjacent();
    bool belongs_to_enemy_player(tact::Character *character);
    void draw_units(sf::RenderWindow &window, tact::Player player);
    void foo();
};


#endif //CIS29GROUP2GAME_GAME_H
