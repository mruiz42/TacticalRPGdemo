//
// Created by michael on 2/19/20.
//

#include "../../include/tact/Game.h"



Game::Game() : cur(0, 0),
    sidebar(root_prefix + sidebar_bg_path , root_prefix + sidebar_font_path),
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
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if(this->get_current_player().is_turn_end()){
                this->swap_turns();
                sidebar.setTurn("Player" + std::to_string(get_current_player_id() + 1) +" turn");
            }

            if (c_map.get_map()[cur.get_y()][cur.get_x()] != nullptr) {
                sidebar.update_statbar(c_map.get_character_at(cur), cur, turn_count, get_current_player().get_player_id());
            }

            else {
                sidebar.clear();
                sidebar.update_sidebar(cur, turn_count, get_current_player_id());
            }
            // Poll for events
            switch (event.type) {
                case sf::Event::Closed: {
                    window.close();
                    break;
                }

            }
            if (event.type == sf::Event::JoystickMoved || event.type == sf::Event::JoystickButtonReleased) {
                joy_poll_logic();
            }
            else if (event.type == sf::Event::KeyPressed) {
                poll_key_logic();
            }

            window.clear();
            update_map();
            window.draw(v_map);
            window.draw(c_map);
            window.draw(cur.get_sprite());
            window.draw(sidebar);
            window.draw(sidebar.get_menu());
            sidebar.drawStat(window);
            window.display();
        }
    }
    std::cout << "Game Over!" << std::endl;
    return 0;
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

bool Game::belongs_to_current_player(Character* character) {
    for (auto i = 0; i < this->get_current_player().get_squadron().size(); i++) {
        if (character == this->get_current_player().get_squadron()[i]) {
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
    for (int y = 0; y < 22; ++y) {
        for (int x = 0; x < 32; ++x) {
            c_map.get_map()[y][x] = nullptr;
        }
    }
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
            else if (std::abs(xy.get_y() - cur.get_y()) + std::abs(xy.get_x() - cur.get_x()) > selector.get_selection().get_speed() / 5) {
                std::cout << "character can't move that far. ";
                break;
            }

            std::cout << "placed at :" << cur << std::endl;
            c_map.set_character_at(cur, &selector.get_selection());
            c_map.null_character_at(selector.get_selection().get_coordinate());
            selector.get_selection().set_coordinate(cur);
            selector.get_selection().set_moved(true);
            selector.clear_selection();
            unit_selected = false;
            std::cout << "===============" << std::endl;
            break;
        }
        case sf::Keyboard::Key::BackSpace:              // Cancel
            unit_selected = false;
            selector.clear();
            break;
    }
}

int Game::menu_key_poll() {
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
            this->sidebar.get_menu().set_selection_text_color(sf::Color::Cyan);
            return sidebar.get_menu().get_selection();
        }

        case sf::Keyboard::Key::BackSpace: {
            this->sidebar.get_menu().set_selection_text_color(sf::Color::Red);
            sidebar.get_menu().set_all_text_color(sf::Color::White);
            menu_selected = false;
            unit_selected = false;
            return -1;
        }
    }
}

int Game::move_cursor_joy_poll() {
    if(event.type == sf::Event::JoystickMoved) {  // Controller input events
        // Get direction of D pad press
        int p_x = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovX);
        int p_y = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovY);
        std::cout << p_x << " " << p_y << std::endl;
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
    if(event.type == sf::Event::JoystickMoved) { // Controller input events
        // Get direction of D pad press
        int p_x = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovX);
        int p_y = sf::Joystick::getAxisPosition(get_current_player_id(), sf::Joystick::PovY);

        // Down
        if (p_y > 0) {
            sidebar.get_menu().move_down();
            return -1;
        }

        // Up
        else if (p_y < 0) {
            sidebar.get_menu().move_up();
            return -1;
        }

        // Left
        else if (p_x < 0) {
            sidebar.get_menu().move_left();
            return -1;
        }

        // Right
        else if (p_x > 0) {
            sidebar.get_menu().move_right();
            return -1;
        }
    }
    else if(event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickButtonReleased) {
        if (sf::Joystick::isButtonPressed(get_current_player_id(), 0)) {
            sidebar.get_menu().set_selection_text_color(sf::Color::Cyan);
            return sidebar.get_menu().get_selection();
        }
        else if (sf::Joystick::isButtonPressed(get_current_player_id(), 1)) {
            sidebar.get_menu().set_selection_text_color(sf::Color::Red);
            sidebar.get_menu().set_all_text_color(sf::Color::White);
            menu_selected = false;
            unit_selected = false;
            return -1;
        }
    }

}

void Game::poll_key_logic() {
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
            switch(selection && selection) {
                case 0: // Move
                    move_selected = true;
                    menu_selected = false;
                    break;
                case 1: // Wait
                    wait_selected = true;
                    menu_selected = false;
                    break;
                case 2: // Attack
                    attack_selected = true;
                    menu_selected = false;
                    break;
                case 3: // Defend
                    defend_selected = true;
                    menu_selected = false;
                    break;
            }
        }
    }

    else if (move_selected){
        move_character_key_poll();
    }

    else if (defend_selected) {

    }

    else if (attack_selected) {

    }

    else if (wait_selected) {

    }
}

void Game::joy_poll_logic() {
    adjust_volume_key_poll();
    // Move cursor routine
    if (!unit_selected) {
        if (event.type == sf::Event::JoystickMoved || event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickButtonReleased) {
            move_cursor_joy_poll();
        }
    }
        // Menu selection routine
    else if (menu_selected) {
        int selection = -1;
        if (event.type == sf::Event::JoystickMoved || event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickButtonReleased) {
            selection = menu_joy_poll();
        }
        if (selection != -1) {
            switch(selection && selection) {
                case 0: // Move
                    move_selected = true;
                    menu_selected = false;
                    break;
                case 1: // Wait
                    wait_selected = true;
                    menu_selected = false;
                    break;
                case 2: // Attack
                    attack_selected = true;
                    menu_selected = false;
                    break;
                case 3: // Defend
                    defend_selected = true;
                    menu_selected = false;
                    break;
            }
        }
    }

    else if (move_selected){
        move_character_key_poll();
    }

    else if (defend_selected) {

    }

    else if (attack_selected) {

    }

    else if (wait_selected) {

    }
}