//
// Created by michael on 2/19/20.
//

#include "../../include/tact/Game.h"


Game::Game() : cur(root_prefix + cur_path, 0, 0),
    sidebar(root_prefix + sidebar_bg_path , root_prefix + sidebar_font_path) {


}
int Game::play_game(sf::RenderWindow& window) {


    const unsigned int num_tiles_x = (WINDOW_WIDTH - (TEXTURE_SIZE * 8)) / TEXTURE_SIZE;
    const unsigned int num_tiles_y = WINDOW_HEIGHT / TEXTURE_SIZE;
    const unsigned int num_tiles_total = num_tiles_x * num_tiles_y;

    // create the tilemap from the level definition

    if (!v_map.loadMap(root_prefix + map_texture_path, root_prefix + cur_path,
                       sf::Vector2u(TEXTURE_SIZE, TEXTURE_SIZE), num_tiles_x, num_tiles_y))
        return -1;

    // Cursor

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
    if(!buffer.loadFromFile(root_prefix + "share/audio/volume_change.wav")){
        std::cout << "Error: sound effect." << std::endl;
        return -1;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(50);	/// range 0-100
    std::cout << sf::Joystick::getButtonCount(0) << std::endl;

    /// display character's info on sidebar
    sidebar.createStat(WINDOW_WIDTH, WINDOW_HEIGHT, root_prefix + font_path);

    while (window.isOpen())
    {
        while (window.pollEvent(event)) {
            sidebar.setTurn("- HumanPlayer 1 turn -");
            void updateStatbar(Character *);

            if (c_map.getSpritemap()[cur.y_pos/32][cur.x_pos/32] != nullptr) {
                sidebar.updateStatbar(c_map.get_character_at(cur.x_pos / 32, cur.y_pos / 32));
//                std::cout<< cur.x_pos/32 << " " << cur.y_pos/32 << "\n";
            }
//            else if (v_map.getSpritemap()[cur.y_pos/32][cur.x_pos/32] < 69){
//
//            }
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
                    }

                case sf::Event::MouseButtonPressed:  // Mouse events
                    if(event.MouseButtonPressed == sf::Mouse::Left){
//						sidebar.hp_raise(HP, HP_MAX, HP_RAISE, window.getSize().x, window.getSize().y, root_path + fontFileName, window);
                        std::cout << "Mouse left button pressed" << std:: endl;
                    }
                    break;
            }

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