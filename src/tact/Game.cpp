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
    check_controllers();
    std::cout << "- Start Game -\n";
    player1.set_is_turn(true);

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
    while (window.isOpen())
    {
        update_map();

        while (window.pollEvent(event)) {
            sidebar.setTurn("- Player 1 turn -");
            if (c_map.get_map()[cur.get_tile_y()][cur.get_tile_x()] != nullptr) {
                sidebar.updateStatbar(c_map.get_character_at(cur.get_tile_x(), cur.get_tile_y()));
            }
            else if (v_map.get_type_at(cur.get_tile_x(), cur.get_tile_y()) >= 69){
//                std::cout << "impassible " << std::endl;
            }
            else {
                sidebar.clear();
            }
            // Poll for events
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:     // Keyboard input events
                    switch(event.key.code)
                    {
                        case sf::Keyboard::D:   // Right
                            if (cur.get_sprite().getPosition().x < 992)
                                cur.moveSprite(TEXTURE_SIZE, 0);
                            break;

                        case sf::Keyboard::A:  // Left
                            if (cur.get_sprite().getPosition().x > 0)
                                cur.moveSprite(-TEXTURE_SIZE, 0);
                            break;

                        case sf::Keyboard::W: // UP
                            if (cur.get_sprite().getPosition().y > 0)
                                cur.moveSprite(0, -TEXTURE_SIZE);
                            break;

                        case sf::Keyboard::S: // DOWN
                            if (cur.get_sprite().getPosition().y < 672)
                                cur.moveSprite(0, TEXTURE_SIZE);
                            break;

                        case sf::Keyboard::Key::Dash: // Volume Down
                            music.setVolume(music.getVolume() - 10);
                            sound.setVolume(sound.getVolume() - 10);
                            sound.play();
                            break;

                        case sf::Keyboard::Key::Equal:  // Volume Up
                            music.setVolume(music.getVolume() + 10);
                            sound.setVolume(sound.getVolume() + 10);
                            sound.play();
                            if (music.getVolume() >= 100){
                                music.setVolume(100);
                                sound.setVolume(100);
                            }
                            break;
                        case sf::Keyboard::Key::Enter:
                            std::cout << cur << std::endl;
                            if (belongs_to_current_player(c_map.get_character_at(cur.get_tile_coordinate()))) {
                                std::cout << "can move it : P" << std::endl;
                            }
//                                if (v_map.get_type_at(cur.get_coordinate()) < 69 && c_map.get_character_at(cur.get_coordinate()) )

                            break;
                        case sf::Keyboard::Key::Q:
                            if (iterator == get_current_player().get_squadron().size())
                                iterator = 0;
                            Character* ptr = get_current_player().get_squadron()[iterator];
                            cur.set_coordinate(ptr->get_coordinate());
                            cur.jump_to(cur.get_x(), cur.get_y());
                            iterator++;
                            break;
                    }

                case sf::Event::MouseButtonPressed:  // Mouse events
                    if(event.MouseButtonPressed == sf::Mouse::Left){
//						sidebar.hp_raise(HP, HP_MAX, HP_RAISE, window.getSize().x, window.getSize().y, root_path + fontFileName, window);
                        std::cout << "Mouse left button pressed" << std:: endl;
                    }
                    break;
            }

            get_current_player().get_controller().poll(event, cur, get_current_player_id());
        }
        // Refresh screen
        window.clear();
//        for (int y = 0; y < 22; ++y){
//            for (int x = 0; x < 32; ++x){
//                std::cout << c_map.getSpritemap()[y][x] << "\t";
//             }
//            std::cout << std::endl;
//    }
        window.draw(v_map);
        window.draw(c_map);
        window.draw(cur.get_sprite());
        window.draw(sidebar);
        sidebar.drawStat(window);
        window.display();
    }
    std::cout << "Game Over!" << std::endl;
    return 0;
}

int Game::toggle_music() {

    return 0;
}

int Game::swap_turns(){
    std::cout << "- End turn - \n";
    if (player1.get_is_turn()){
        std::cout << "- Player " + std::to_string(player2.get_player_id()) << "'s Turn begin -\n";
        player1.set_is_turn(false);
        player2.set_is_turn(true);
    }
    else if (player2.get_is_turn()) {
        std::cout << "Player " + std::to_string(player1.get_player_id()) << "'s Turn begin -\n";
        player2.set_is_turn(false);
        player1.set_is_turn(true);
    }
    else {
        std::cout << "ERROR! Should probably throw something, because this shouldn't have happened...!!!" << std::endl;
    }
}

HumanPlayer& Game::get_current_player() {
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

HumanPlayer& Game::get_enemy_player() {
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
        } else {
            return false;
        }
    }
}

int Game::check_controllers() {
    if (player1.get_controller().get_js().isConnected(0) && player1.get_controller().get_js().isConnected(1)) {
        return 0;
    }
    else {
        std::cout << "Only one controller detected! " << std::endl;
        return 1001;
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