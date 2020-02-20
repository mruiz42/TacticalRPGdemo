//
// Created by michael on 2/19/20.
//

#include "../../include/tact/Game.h"

int Game::load_game(sf::RenderWindow& window) {

    Sidebar sidebar(root_path + "share/textures/sidebar_background.png", root_path + "share/resources/ChunkyDunk.ttf");

    const unsigned int num_tiles_x = (WINDOW_WIDTH - (TEXTURE_SIZE * 8)) / TEXTURE_SIZE;
    const unsigned int num_tiles_y = WINDOW_HEIGHT / TEXTURE_SIZE;
    const unsigned int num_tiles_total = num_tiles_x * num_tiles_y;

    // create the tilemap from the level definition
    VertexMap v_map;
    CharacterMap c_map;
    if (!v_map.loadMap(root_path + "share/textures/map_tiles32.png", root_path + "share/sprites/cursor.png",
                       sf::Vector2u(TEXTURE_SIZE, TEXTURE_SIZE), num_tiles_x, num_tiles_y))
        return -1;

    // Cursor
    Cursor cur("./share/sprites/cursor.png", 0, 0);

    // add background music (stream directly from music file)
    sf::Music music;
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
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile(root_path + "share/audio/volume_change.wav")){
        std::cout << "Error: sound effect." << std::endl;
        return -1;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(50);	/// range 0-100
    std::cout << sf::Joystick::getButtonCount(0) << std::endl;

    /// display character's info on sidebar
    sidebar.createStat(WINDOW_WIDTH, WINDOW_HEIGHT, root_path + fontFileName);

    while (window.isOpen())
    {

        sf::Event event;
        // <Main game loop>
        while (window.pollEvent(event)) {

            sidebar.setTurn("- Player 1 turn -");	void updateStatbar(Character *);

            if (c_map.getSpritemap()[cur.y_pos/32][cur.x_pos/32] != nullptr) {
                sidebar.updateStatbar(c_map.get_character_at(cur.x_pos / 32, cur.y_pos / 32));
                std::cout<< cur.x_pos/32 << " " << cur.y_pos/32 << "\n";

            }
            else { sidebar.clear();                std::cout << cur.x_pos/32 << " " << cur.y_pos/32 << "\n"; }
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
                    if(event.key.code == sf::Mouse::Left){
//						sidebar.hp_raise(HP, HP_MAX, HP_RAISE, window.getSize().x, window.getSize().y, root_path + fontFileName, window);
                        std::cout << "Mouse left button pressed" << std:: endl;
                    }
                    break;
            }
            if(event.type == sf::Event::JoystickMoved)  // Controller input events
            {
                // Get direction of D pad press
                int p_x = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX);
                int p_y = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY);
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
                std::cout << "(" << cur.get_sprite().getPosition().x << "," << cur.get_sprite().getPosition().y << std::endl;
            }
//			std::cout << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << std::endl;
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


}