//
// Created by michael on 2/19/20.
//

#include "../../include/tact/Game.h"


Game::Game() : cur(0, 0),
    sidebar(root_prefix + sidebar_bg_path , root_prefix + sidebar_font_path) {
    players[0].set_player_id(0);
    players[1].set_player_id(1);

    check_controllers();
    std::cout << "- Start Game -\n";
    players[0].set_is_turn(true);
//    players[0].get_fort()->set_coordinate(17, 2);
    players[0].set_fort_coord(2, 17);
    players[1].set_fort_coord(29, 4);

    for (int p = 0; p < 2; p++) {
        HumanPlayer* p_ptr = &players[p];
//        p_ptr[p].get_squadron().resize(p_ptr->get_number_units());
        for (int s = 0; s < players[p].get_number_units(); s++) {
            p_ptr->get_squadron().push_back(new Ninja(p_ptr->get_fort().get_coordinate().x + s, p_ptr->get_fort().get_coordinate().y + 1 + s));
        }
    }

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
        while (window.pollEvent(event)) {
            sidebar.setTurn("- Player 1 turn -");
            void updateStatbar(Character *);

            if (c_map.getSpritemap()[cur.get_x()/32][cur.get_y()/32] != nullptr) {
                sidebar.updateStatbar(c_map.get_character_at(cur.get_x() / 32, cur.get_y() / 32));
            }
            else if (v_map.get_type_at(cur.get_x()/32, cur.get_y()/32) >= 69){
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
                        case sf::Keyboard::Key::Q:
                            Character* ptr = get_current_player().get_squadron()[0];
                            std::cout << ptr->get_coordinate().get_x() << " " << ptr->get_coordinate().get_y() << std::endl;
                            cur.set_coordinate(ptr->get_coordinate().get_x(), ptr->get_coordinate().get_y());

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
    if (players[0].get_is_turn()){
        std::cout << "- Player " + std::to_string(players[1].get_player_id()) << "'s Turn begin -\n";
        players[0].set_is_turn(false);
        players[1].set_is_turn(true);
    }
    else if (players[1].get_is_turn()) {
        std::cout << "Player " + std::to_string(players[0].get_player_id()) << "'s Turn begin -\n";
        players[1].set_is_turn(false);
        players[0].set_is_turn(true);
    }
    else {
        std::cout << "ERROR! Should probably throw something, because this shouldn't have happened...!!!" << std::endl;
    }
}

HumanPlayer& Game::get_current_player() {
    if (players[0].get_is_turn()) {
        return players[0];
    }
    else if (players[1].get_is_turn()) {
        return players[1];
    }
    else {
        std::cout << "ERROR! Should probably throw something, because this shouldn't have happened...!!!" << std::endl;
    }
}

int Game::get_current_player_id() {
    if (players[0].get_is_turn()) {
        return players[0].get_player_id();
    }
    else if (players[1].get_is_turn()) {
        return players[1].get_player_id();
    }
    else {
        std::cout << "ERROR! Should probably throw something, because this shouldn't have happened...!!!" << std::endl;
    }
}


int Game::check_controllers() {
    if (players[0].get_controller().get_js().isConnected(0) && players[0].get_controller().get_js().isConnected(1)) {
        return 0;
    }
    else {
        std::cout << "Only one controller detected! " << std::endl;
        return 420;
    }
}