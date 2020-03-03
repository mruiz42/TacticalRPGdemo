//
// Created by michael on 2/19/20.
//

#include "../../include/tact/Game.h"
#include <cstdlib>
#include <ctime>
#include <cmath>


Game::Game() : cur(0, 0),
    sidebar(root_prefix + sidebar_bg_path , root_prefix + sidebar_font_path, root_prefix + battleLog_font_path ),
    player1(0, Coordinate(2, 17)),
    player2(1, Coordinate(29, 3))
    {
    iterator = 0;
    turn_count = 1;
    unit_selected = false;
    menu_selected = false;
    move_selected = false;
    attack_selected = false;
    defend_selected = false;
    wait_selected = false;
    check_controllers();
	sidebar.update_battleLog("- Start Game -");
    std::cout << "- Start Game -\n";
    player1.set_is_turn(true);
    sidebar.setTurn("Player" + std::to_string(get_current_player_id() + 1) + " turn");
    cur.jump_to(get_current_player().get_squadron()[0]->get_coordinate());
    if (!v_map.loadMap(root_prefix + map_texture_path, root_prefix + cur_path, sf::Vector2u(TEXTURE_SIZE, TEXTURE_SIZE), num_tiles_x, num_tiles_y)) {
//        return -1;
    }
    // add background music (stream directly from music file)
//	if(!music.openFromFile(root_path + "share/audio/BattleTheme.wav")){
//		std::cout << "Error: backgound music." << std::endl;
//		return -1;
//	}
//	if(!music.openFromFile(root_path + "share/audio/Vanadiel_March.wav")){
//		std::cout << "Error: backgound music." << std::endl;
//		return -1;
//	}
    music.setVolume(50);  /// range 0 - 100
    music.play();

    // add sound effect (pre-load small audio file to memory for fast response)
    // credit to https://www.noiseforfun.com/2012-sound-effects/menu-05-a/
    if(!buffer.loadFromFile(root_prefix + vol_change_sound_path)){
        std::cout << "Error: sound effect: " + vol_change_sound_path + " could not be loaded." << std::endl;
//        return -1;
    }
    sound.setBuffer(buffer);
    sound.setVolume(50);	/// range 0-100

    /// display character's info on sidebar
    sidebar.createStat(WINDOW_WIDTH, WINDOW_HEIGHT, root_prefix + font_path);
}

int Game::play_game(sf::RenderWindow& window) {
    window.setFramerateLimit(60);
	bool gameEnd = false;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if(this->get_current_player().is_turn_end()){
                this->swap_turns();
                menu_selected = false;
                move_selected = false;
                attack_selected = false;
                unit_selected = false;
                defend_selected = false;
                wait_selected = false;
                sidebar.setTurn("Player" + std::to_string(get_current_player_id() + 1) +" turn");
            }
			if (get_enemy_player().get_squadron().size() == 0) {
				sidebar.update_battleLog("Player " + std::to_string(get_current_player_id() + 1) + " wins!");
				sidebar.drawBattleLog(window);
				std::cout << "Player " << get_current_player_id() + 1 << " wins!" << std::endl;
				gameEnd = true;
				break;
			}
			if (get_current_player().get_squadron().size() == 0) {
				sidebar.update_battleLog("Player " + std::to_string(get_enemy_player_id() + 1) + " wins!");
				sidebar.drawBattleLog(window);
				std::cout << "Player " << get_enemy_player_id() + 1 << " wins!" << std::endl;
				gameEnd = true;
				break;
			}
			
            if (c_map.get_map()[cur.get_y()][cur.get_x()] != nullptr) {
				if (belongs_to_current_player(c_map.get_character_at(cur))) {
					sidebar.update_statbar(c_map.get_character_at(cur), cur, turn_count, get_current_player_id());
				} else {
					sidebar.update_statbar(c_map.get_character_at(cur), cur, turn_count, get_enemy_player_id());
				}
            }

            else {
                sidebar.clear();
                sidebar.update_sidebar(cur, turn_count, get_current_player_id());
            }

            /*
            if (selector.get_selection().get_coordinate() != nullptr) {
                Coordinate origin_xy = selector.get_selection().get_coordinate();
                float origin_x = origin_xy.get_map_x();
                float origin_y = origin_xy.get_map_y();
            }
            }
            */
            // Poll for events
            switch (event.type) {
                case sf::Event::Closed: {
                    window.close();
                    break;
                }

            }
            if (event.type == sf::Event::JoystickMoved || event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickButtonReleased) {
                poll_joy_logic();
            }
            else if (event.type == sf::Event::KeyPressed) {
                poll_key_logic(window);
            }

            window.clear();
            update_map();
            window.draw(v_map);
            
            window.draw(c_map);

            window.draw(cur.get_sprite());
            window.draw(sidebar);
            window.draw(sidebar.get_menu());
            sidebar.drawStat(window);
			sidebar.drawBattleLog(window);
            window.display();
        }
		if (gameEnd) break;
    }
    std::cout << "Game Over!" << std::endl;
    return 0;
}
void Game::poll_key_logic(sf::RenderWindow& window) {
    adjust_volume_key_poll();
    // Move cursor routine
    if (!unit_selected) {
        if (event.type == sf::Event::KeyPressed) {
            move_cursor_key_poll();
        }
    }
    // Menu selection routine
    else if (menu_selected) {
        int selection = -1;
        if (event.type == sf::Event::KeyPressed) {
            selection = menu_key_poll();
        }
        if (selection != -1) {
            switch(selection) {
                case 0: // Move
                    move_selected = true;
                    menu_selected = false;
                    break;
                case 1: // Wait
                    selector.get_selection().set_can_attack(false);
                    wait_selected = true;
                    move_selected = false;
                    menu_selected = false;
                    break;
                case 2: // Attack
                    attack_selected = true;
                    move_selected = false;
                    menu_selected = false;
                    break;
                case 3: // Defend
                    selector.get_selection().set_can_attack(false);
                    defend_selected = true;
                    move_selected = false;
                    menu_selected = false;
                    break;
            }
        }
    }


    else if (move_selected){
        move_character_key_poll();
    }

    else if (defend_selected) {
        defend_character_poll();
    }

    else if (attack_selected) {
        attack_character_key_poll(window);
    }

    else if (wait_selected) {
        wait_character_poll();
    }
}

void Game::poll_joy_logic() {
    adjust_volume_key_poll();
    // Move cursor routine
    if (!unit_selected) {
        if (event.type == sf::Event::JoystickMoved || event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickButtonReleased) {
            move_cursor_joy_poll();
        }
    }
        // Menu selection routine
    else if (menu_selected) {
        int selection = menu_joy_poll();
        if (selection == -1) {
            return;
        }
        else if (selection == 0) {
            move_selected = true;
            menu_selected = false;
            return;
        }
        else if (selection == 1) { // Wait
            wait_selected = true;
            menu_selected = false;
            return;
        }
        else if (selection == 2) { // Attack
            attack_selected = true;
            menu_selected = false;
            return;
        }
        else if (selection == 3) { // Defend
            defend_selected = true;
            menu_selected = false;
            return;

        }
    }

    else if (move_selected){
        move_character_joy_poll();
    }

    else if (defend_selected) {

    }

    else if (attack_selected) {

    }

    else if (wait_selected) {

    }
}

int Game::toggle_music() {

    return 0;
}

int Game::swap_turns(){
    std::cout << "- End turn - \n";
    turn_count++;
    if (player1.get_is_turn()){
        std::cout << "- Player " + std::to_string(player2.get_player_id() + 1) << "'s Turn begin -\n";
        player1.set_is_turn(false);
        player2.set_is_turn(true);
        player2.reset_squaderon_exhaustion();
        cur.jump_to(player2.get_squadron()[0]->get_coordinate());
        selector.clear();
        return player2.get_player_id();
    }
    else if (player2.get_is_turn()) {
        std::cout << "Player " + std::to_string(player1.get_player_id() + 1) << "'s Turn begin -\n";
        player2.set_is_turn(false);
        player1.set_is_turn(true);
        player1.reset_squaderon_exhaustion();
        cur.jump_to(player1.get_squadron()[0]->get_coordinate());
        selector.clear();
        return player1.get_player_id();
    }
    else {
        std::cout << "ERROR! Should probably throw something, because this shouldn't have happened...!!!" << std::endl;
    }
}

Player& Game::get_current_player() {
    if (player1.get_is_turn()) {
        return player1;
    }
    else if (player2.get_is_turn()) {
        return player2;
    }
    else {
        std::cout << "ERROR! Should probably throw something, because this shouldn't have happened...!!!" << std::endl;
    }
}

Player& Game::get_enemy_player() {
    if (player1.get_is_turn()) {
        return player2;
    }
    else if (player2.get_is_turn()) {
        return player1;
    }
    else {
        std::cout << "ERROR! Should probably throw something, because this shouldn't have happened...!!!" << std::endl;
    }
}

bool Game::has_enemy_adjacent(){
    Coordinate xy = selector.get_selection().get_coordinate();
    const Player* enemy_player = &get_enemy_player();
    int x = xy.get_x();
    int y = xy.get_y();
    Character* up = c_map.get_character_at(x, y-1);
    Character* down = c_map.get_character_at(x, y+1);
    Character* left = c_map.get_character_at(x-1, y);
    Character* right = c_map.get_character_at(x+1, y);
    if (belongs_to_enemy_player(up) && up != nullptr) {
        return true;
    }
    else if (belongs_to_enemy_player(down) && down != nullptr) {
        return true;
    }
    else if (belongs_to_enemy_player(left) && left != nullptr) {
        return true;
    }
    else if (belongs_to_enemy_player(right) && right != nullptr) {
        return true;
    }
    return false;
}

int Game::get_current_player_id() {
    if (player1.get_is_turn()) {
        return player1.get_player_id();
    }
    else if (player2.get_is_turn()) {
        return player2.get_player_id();
    }
    else {
        std::cout << "ERROR! Should probably throw something, because this shouldn't have happened...!!!" << std::endl;
    }
}

int Game::get_enemy_player_id() {
    if (player1.get_is_turn()) {
        return player2.get_player_id();
    }
    else if (player2.get_is_turn()) {
        return player1.get_player_id();
    }
    else {
        std::cout << "ERROR! Should probably throw something, because this shouldn't have happened...!!!" << std::endl;
    }
}


bool Game::belongs_to_current_player(Character* character) {
    for (auto i = 0; i < this->get_current_player().get_squadron().size(); i++) {
        if (character == this->get_current_player().get_squadron()[i]) {
            return true;
        }
    }
    return false;
}

bool Game::belongs_to_enemy_player(Character* character){
    for (auto i = 0; i < this->get_enemy_player().get_squadron().size(); i++) {
        if (character == this->get_enemy_player().get_squadron()[i]) {
            return true;
        }
    }
    return false;
}

int Game::check_controllers() {
    if (sf::Joystick::isConnected(0) && sf::Joystick::isConnected(1)) {
        std::cout << "Two controller detected! \n" << std::endl;
        return 2;
    }
    else if (sf::Joystick::isConnected(0) || sf::Joystick::isConnected(1)) {
        std::cout << "One controller detected! \n" << std::endl;
        return 1;
    }
    else {
        std::cout << "No controllers detected! \n" << std::endl;
        return 0;
    }
}

void Game::update_map() {
//    for (int y = 0; y < 22; ++y) {
//        for (int x = 0; x < 32; ++x) {
//            c_map.get_map()[y][x] = nullptr;
//        }
//    }
    for (int i = 0; i < player1.get_squadron().size(); i++) {
        c_map.set_character_at(player1.get_squadron().at(i)->get_coordinate(), player1.get_squadron().at(i));
    }
    for (int i = 0; i < player2.get_squadron().size(); i++) {
        c_map.set_character_at(player2.get_squadron().at(i)->get_coordinate(), player2.get_squadron().at(i));
    }
}
/*****sound/mucis code needs update ****/
void Game::adjust_volume_key_poll() {
    switch (event.key.code) {
        case sf::Keyboard::Key::Dash: // Volume Down
            music.setVolume(music.getVolume() - 10);
            sound.setVolume(sound.getVolume() - 10);
            sound.play();
            break;

        case sf::Keyboard::Key::Equal:  // Volume Up
            music.setVolume(music.getVolume() + 10);
            sound.setVolume(sound.getVolume() + 10);
            sound.play();
            if (music.getVolume() >= 100) {
                music.setVolume(100);
                sound.setVolume(100);
            }
            break;
    }
}

void Game::move_cursor_key_poll() {
    switch (event.key.code) {
        case sf::Keyboard::Key::D:   // Right
            if (cur.get_sprite().getPosition().x < 992)
                cur.moveSprite(TEXTURE_SIZE, 0);
            break;

        case sf::Keyboard::Key::A:  // Left
            if (cur.get_sprite().getPosition().x > 0)
                cur.moveSprite(-TEXTURE_SIZE, 0);
            break;

        case sf::Keyboard::Key::W: // UP
            if (cur.get_sprite().getPosition().y > 0)
                cur.moveSprite(0, -TEXTURE_SIZE);
            break;

        case sf::Keyboard::Key::S: // DOWN
            if (cur.get_sprite().getPosition().y < 672)
                cur.moveSprite(0, TEXTURE_SIZE);
            break;

        case sf::Keyboard::Key::Return: {         // Pick up
            std::cout << cur << std::endl;
            Character *c_ptr = c_map.get_character_at(cur);
            if (c_ptr != nullptr && belongs_to_current_player(c_ptr) && !c_ptr->is_moved()) {
                unit_selected = true;
                menu_selected = true;
                selector.set_selection(c_map.get_character_at(cur));
            }
            break;
        }
        case sf::Keyboard::Key::Q:
            if (iterator == get_current_player().get_squadron().size())
                iterator = 0;
            Character* c_ptr = get_current_player().get_next_character(iterator);
            cur.jump_to(c_ptr->get_coordinate());
            iterator++;
            break;
    }
}

void Game::move_character_key_poll(){
    std::cout << "pickedup ";
    switch (event.key.code) {
        case sf::Keyboard::Key::D:   // Right
            if (cur.get_sprite().getPosition().x < 992){
                cur.moveSprite(TEXTURE_SIZE, 0);
                selector.get_selection().get_map_sprite().move(TEXTURE_SIZE, 0);
            }
            break;

        case sf::Keyboard::Key::A:  // Left
            if (cur.get_sprite().getPosition().x > 0) {
                cur.moveSprite(-TEXTURE_SIZE, 0);
                selector.get_selection().get_map_sprite().move(-TEXTURE_SIZE, 0);
            }
            break;

        case sf::Keyboard::Key::W: // UP
            if (cur.get_sprite().getPosition().y > 0) {
                cur.moveSprite(0, -TEXTURE_SIZE);
                selector.get_selection().get_map_sprite().move(0, -TEXTURE_SIZE);
            }
            break;

        case sf::Keyboard::Key::S: // DOWN
            if (cur.get_sprite().getPosition().y < 672) {
                cur.moveSprite(0, TEXTURE_SIZE);
                selector.get_selection().get_map_sprite().move(0, TEXTURE_SIZE);
            }
            break;

        case sf::Keyboard::Key::Return: {                  // Set down
            Coordinate xy = selector.get_selection().get_coordinate();
            if (c_map.get_map()[cur.get_y()][cur.get_x()] != nullptr) {
                sidebar.update_statbar(c_map.get_character_at(cur), cur, turn_count, get_current_player().get_player_id());
                break;
            }
            else if (v_map.get_type_at(cur) >= 69) {
                std::cout << "impassible ";
                break;
            }
//            else if (std::abs(xy.get_y() - cur.get_y()) + std::abs(xy.get_x() - cur.get_x()) > selector.get_selection().get_speed() / 5) {
//                std::cout << "character can't move that far. ";
//                break;
//            }

            std::cout << "placed at :" << cur << std::endl;
            c_map.set_character_at(cur, &selector.get_selection());
            c_map.null_character_at(selector.get_selection().get_coordinate());
            selector.get_selection().set_coordinate(cur);

            if (has_enemy_adjacent()) {
                selector.get_selection().set_moved(true);
                selector.get_selection().set_can_attack(true);
                std::cout << "enemy adjacent!" << std::endl;
                menu_selected = true;
                move_selected = false;
                //unit_selected = false;
            }
            else {
                selector.get_selection().set_moved(true);
//                selector.clear_selection();
                menu_selected = true;
                //unit_selected = false;
            }
            break;
        }
        case sf::Keyboard::Key::BackSpace:              // Cancel
            unit_selected = false;
            selector.clear();
            break;
    }
}
int Game::menu_key_poll() {
    if (has_enemy_adjacent()){
        this->selector.get_selection().set_can_attack(true);
    }
    else {
        sidebar.get_menu().set_one_text_color(sf::Color(128,128,128,255), 2);
    }
    if (selector.get_selection().is_moved()){
        sidebar.get_menu().set_one_text_color(sf::Color(128,128,128,255), 0);
    }
    switch (event.key.code) {
        case sf::Keyboard::Key::D:   // Right
            this->sidebar.get_menu().move_right();
            return -1;

        case sf::Keyboard::Key::A:  // Left
            this->sidebar.get_menu().move_left();
            return -1;

        case sf::Keyboard::Key::W: // UP
            this->sidebar.get_menu().move_up();
            return -1;

        case sf::Keyboard::Key::S: // DOWN
            this->sidebar.get_menu().move_down();
            return -1;

        case sf::Keyboard::Key::Return: {         // Pick up
            int menu_selection = sidebar.get_menu().get_selection();
            if (menu_selection == 0 && selector.get_selection().is_moved()) {
                return -1;
            }
            else if (menu_selection == 2 && !this->selector.get_selection().can_attack()) {
                return -1;
            }
            this->sidebar.get_menu().set_selection_text_color(sf::Color::Cyan);
            return menu_selection;
        }

        case sf::Keyboard::Key::BackSpace: {
            this->sidebar.get_menu().set_selection_text_color(sf::Color::Red);
            menu_selected = false;
            unit_selected = false;
            return -1;
        }
    }
}
int Game::move_cursor_joy_poll() {
    if(event.type == sf::Event::JoystickMoved) {  // Controller input events
        // Get direction of D pad press
        float p_x = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovX);
        float p_y = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovY);
        // Down
        if (p_y > 0) {
            if (cur.get_sprite().getPosition().y < 672)
                cur.moveSprite(0, TEXTURE_SIZE);
        }
            // Up
        else if (p_y < 0) {
            if (cur.get_sprite().getPosition().y > 0)
                cur.moveSprite(0, -TEXTURE_SIZE);
        }
            // Left
        else if (p_x < 0) {
            if (cur.get_sprite().getPosition().x > 0)
                cur.moveSprite(-TEXTURE_SIZE, 0);
        }
            // Right
        else if (p_x > 0) {
            if (cur.get_sprite().getPosition().x < 992)
                cur.moveSprite(TEXTURE_SIZE, 0);
        }
    }
    else if (sf::Joystick::isButtonPressed(get_current_player_id(), 0)) {
        std::cout << cur << std::endl;
        Character *c_ptr = c_map.get_character_at(cur);
        if (c_ptr != nullptr && belongs_to_current_player(c_ptr) && !c_ptr->is_moved()) {
            unit_selected = true;
            menu_selected = true;
            selector.set_selection(c_map.get_character_at(cur));
        }
}
    else if (sf::Joystick::isButtonPressed(get_current_player_id(), 4)) {
        if (iterator == get_current_player().get_squadron().size())
            iterator = 0;
        Character* c_ptr = get_current_player().get_next_character(iterator);
        cur.jump_to(c_ptr->get_coordinate());
        iterator++;
    }
}
int Game::menu_joy_poll() {
    int selection = -1;
    if(event.type == sf::Event::JoystickMoved) { // Controller input events
        // Get direction of D pad press
        float p_x = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovX);
        float p_y = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovY);
        std::cout << p_x << " " << p_y << std::endl;

        // Down
        if (p_y > 0) {
            sidebar.get_menu().move_down();
            return selection;
        }

        // Up
        else if (p_y < 0) {
            sidebar.get_menu().move_up();
            return selection;
        }

        // Left
        else if (p_x < 0) {
            sidebar.get_menu().move_left();
            return selection;
        }

        // Right
        else if (p_x > 0) {
            sidebar.get_menu().move_right();
            return selection;
        }
    }
    else if(event.type == sf::Event::JoystickButtonReleased || event.type == sf::Event::JoystickButtonPressed) { // Controller input events
        if (sf::Joystick::isButtonPressed(get_current_player_id(), 0)) {
            sidebar.get_menu().set_selection_text_color(sf::Color::Cyan);
            selection = sidebar.get_menu().get_selection();
            return selection;
        } else if (sf::Joystick::isButtonPressed(get_current_player_id(), 1)) {
            sidebar.get_menu().set_selection_text_color(sf::Color::Red);
            sidebar.get_menu().set_all_text_color(sf::Color::White);
            menu_selected = false;
            unit_selected = false;
            return selection;
        }
    }
    return selection;
}
void Game::move_character_joy_poll() {
    std::cout << "pickedup ";

    if (event.type == sf::Event::JoystickMoved) {  // Controller input events
        // Get direction of D pad press
        float p_x = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovX);
        float p_y = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovY);
        // Down
        if (p_y > 0) {
            if (cur.get_sprite().getPosition().y < 672) {
                cur.moveSprite(0, TEXTURE_SIZE);
                selector.get_selection().get_map_sprite().move(0, TEXTURE_SIZE);
            }
        }
            // Up
        else if (p_y < 0) {
            if (cur.get_sprite().getPosition().y > 0) {
                cur.moveSprite(0, -TEXTURE_SIZE);
                selector.get_selection().get_map_sprite().move(0, -TEXTURE_SIZE);
            }
        }
            // Left
        else if (p_x < 0) {
            if (cur.get_sprite().getPosition().x > 0) {
                cur.moveSprite(-TEXTURE_SIZE, 0);
                selector.get_selection().get_map_sprite().move(-TEXTURE_SIZE, 0);
            }
        }
            // Right
        else if (p_x > 0) {
            if (cur.get_sprite().getPosition().x < 992){
                cur.moveSprite(TEXTURE_SIZE, 0);
                selector.get_selection().get_map_sprite().move(TEXTURE_SIZE, 0);
            }
        }
    }
    else if (event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickButtonReleased)
        if (sf::Joystick::isButtonPressed(get_current_player_id(), 0)) {
            Coordinate xy = selector.get_selection().get_coordinate();
            if (c_map.get_map()[cur.get_y()][cur.get_x()] != nullptr) {
                sidebar.update_statbar(c_map.get_character_at(cur), cur, turn_count, get_current_player().get_player_id());
            }
            else if (v_map.get_type_at(cur) >= 69) {
                std::cout << "impassible ";
            }
//            else if (std::abs(xy.get_y() - cur.get_y()) + std::abs(xy.get_x() - cur.get_x()) > selector.get_selection().get_speed() / 5) {
//                std::cout << "character can't move that far. ";
//            }
            else {
                std::cout << "placed at :" << cur << std::endl;
                c_map.set_character_at(cur, &selector.get_selection());
                c_map.null_character_at(selector.get_selection().get_coordinate());
                selector.get_selection().set_coordinate(cur);
                selector.get_selection().set_moved(true);
                selector.clear_selection();
                unit_selected = false;
            }
        }
        else if (sf::Joystick::isButtonPressed(get_current_player_id(), 1)) {
            unit_selected = false;
            selector.clear();
        }
}
void Game::attack_character_key_poll(sf::RenderWindow& window) {
    Coordinate sprite_coordinate = selector.get_selection().get_coordinate();
    float up_bound = (sprite_coordinate.get_y() * 32 ) - 32;
    float down_bound = (sprite_coordinate.get_y() * 32 ) + 32;
    float left_bound = (sprite_coordinate.get_x() * 32 ) - 32;
    float right_bound = (sprite_coordinate.get_x() * 32 ) + 32;

    switch (event.key.code) {
        case sf::Keyboard::Key::D:   // Right
            if (cur.get_sprite().getPosition().x < 992 && cur.get_sprite().getPosition().x < right_bound)
                cur.moveSprite(TEXTURE_SIZE, 0);
            break;

        case sf::Keyboard::Key::A:  // Left
            if (cur.get_sprite().getPosition().x > 0 && cur.get_sprite().getPosition().x > left_bound)
                cur.moveSprite(-TEXTURE_SIZE, 0);
            break;

        case sf::Keyboard::Key::W: // UP
            if (cur.get_sprite().getPosition().y > 0 && cur.get_sprite().getPosition().y > up_bound)
                cur.moveSprite(0, -TEXTURE_SIZE);
            break;

        case sf::Keyboard::Key::S: // DOWN
            if (cur.get_sprite().getPosition().y < 672 && cur.get_sprite().getPosition().y < down_bound)
                cur.moveSprite(0, TEXTURE_SIZE);
            break;

        case sf::Keyboard::Key::Return: {         // Attack
            std::cout << "Attacking!" << std::endl;
            Character *c_ptr = c_map.get_character_at(cur);
            if (c_ptr != nullptr && !belongs_to_current_player(c_ptr)) {
                unit_selected = false;
                menu_selected = false;
                attack_selected = false;
                selector.set_target(c_map.get_character_at(cur));
                // Do attack call here
                selector.get_selection().set_moved(true);
                selector.get_selection().set_can_attack(false);
				
				// Selection attacks target
				sidebar.update_battleLog("Player " + std::to_string(get_current_player_id() + 1) + " initiates attack." );
				sidebar.drawBattleLog(window);
				attack_character_rules(&get_enemy_player(), &selector.get_selection(), &selector.get_target(), get_current_player_id(), get_enemy_player_id(), window);
				
				// Target can revenge attack if not defending and is still alive.
				if (!selector.get_target().is_defending() && selector.get_target().get_hit_points() > 0) {
					sidebar.update_battleLog("Player " + std::to_string(get_enemy_player_id() + 1) + " revenges." );
					sidebar.drawBattleLog(window);
					attack_character_rules(&get_current_player(), &selector.get_target(), &selector.get_selection(), get_enemy_player_id(), get_current_player_id(), window);
				}
                selector.clear();
				
            }
            break;
        }
        case sf::Keyboard::Key::BackSpace:              // Cancel
            attack_selected = false;
            menu_selected = true;
            break;
    }


}
void Game::attack_character_rules(Player* attackedP, Character* attackerC, Character* attackedC, int attackerPID, int attackedPID, sf::RenderWindow& window) {
	// Get used stats
	int attackedDEF = attackedC->get_defense();
	int attackedHP = attackedC->get_hit_points();
	int attackedATK = attackedC->get_attack();
	int attackedSpeed = attackedC->get_speed();
	
	int attackerDEF = attackerC->get_defense();
	int attackerHP = attackerC->get_hit_points();
	int attackerATK = attackerC->get_attack();
	int attackerSpeed = attackerC->get_speed();
	
	//First attack, attacker > attacked
	double Damage = (double)attackerATK * (double)attackerATK / (double)attackedDEF;
	if (attackedC->is_defending()) {
		sidebar.update_battleLog("Player " + std::to_string(attackedPID + 1) + "'s " + attackedC->get_name() + " defenses!");
		sidebar.drawBattleLog(window);
		Damage /= 2;
	}
	// Chance for zero (evaded) or more attacks, based on speed
	double attackChance = 0.9 * attackerSpeed/(double)attackedSpeed;
	srand (time(NULL) + 1 + attackedPID);
	double attackRoll = (rand() % 100 + 1)/100.0; // random 1 to 100
	int numAttack = 0;
	while (attackRoll < attackChance && attackedHP > 0) {
		numAttack += 1;
		// multiply damage by a random number between 0.9 and 1.1
		srand (time(NULL) + 2 + numAttack + attackedPID);
		double DamageRoll = 90.0 + (rand() % 20 + 1);
		int thisDamage = Damage * DamageRoll / 100.0;
		attackedHP -= round(thisDamage);
		if (attackedHP < 0) attackedHP = 0;
		
		//Update attack chance
		attackChance /= 2;
		srand (time(NULL) + 3 + numAttack + attackedPID);
		attackRoll = (rand() % 100 + 1)/100.0;
	}
	//Print outcome to battle log
	if (numAttack == 0) {
		sidebar.update_battleLog("Player " + std::to_string(attackedPID + 1) + "'s " + attackedC->get_name() + " evades!");
		sidebar.drawBattleLog(window);
	} else if (numAttack == 1){
		sidebar.update_battleLog("Player " + std::to_string(attackerPID + 1) + "'s " + attackerC->get_name() + " attacks!");
		sidebar.update_battleLog("Player " + std::to_string(attackedPID + 1) + "'s " + attackedC->get_name() + " took " + std::to_string(attackedC->get_hit_points() - attackedHP) + " damages!");
		sidebar.drawBattleLog(window);
	}  else {
		sidebar.update_battleLog("Player " + std::to_string(attackerPID + 1) + "'s " + attackerC->get_name() + " attacks " + std::to_string(numAttack) + " times!");
		sidebar.update_battleLog("Player " + std::to_string(attackedPID + 1) + "'s " + attackedC->get_name() + " took " + std::to_string(attackedC->get_hit_points() - attackedHP) + " damages!");
		sidebar.drawBattleLog(window);
	}
	attackedC->set_hit_points(attackedHP);
	if (attackedHP == 0) {
		sidebar.update_battleLog("Player " + std::to_string(attackedPID + 1) + "'s " + attackedC->get_name() + " is dead!");
		c_map.null_character_at(attackedC->get_coordinate());
		attackedC = nullptr;
		for (int thischar = 0; thischar < attackedP->get_squadron().size(); thischar++) {
			if (attackedP->get_squadron()[thischar]->get_hit_points() == 0) {
				attackedP->get_squadron().erase(attackedP->get_squadron().begin()+thischar);
				break;
			}
		}
	}
}

void Game::wait_character_poll() {
    menu_selected = false;
    move_selected = false;
    unit_selected = false;
    wait_selected = false;
    selector.get_selection().set_moved(true);
    selector.clear();
}

void Game::defend_character_poll() {
    menu_selected = false;
    move_selected = false;
    unit_selected = false;
    defend_selected = false;
    selector.get_selection().set_defending(true);
    selector.get_selection().set_moved(true);
    selector.clear();
}

