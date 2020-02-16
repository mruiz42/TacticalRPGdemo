#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "../include/tact/VertexMap.h"
#include <string>
#include "../include/tact/Knight.h"
#include "../include/tact/Character.h"
#include <iostream>
#include "../include/tact/Cursor.h"
#include "../include/tact/Sidebar.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 704
#define TEXTURE_SIZE 32

const std::string root_path = "./";    // Linux
// Can someone make a standard windows path that will work?
// const std::string root_path = "C:/";    // Windows

///#pragma once ???


int main()
{
    Sidebar sidebar(root_path + "share/textures/sidebar_background.png");

    const unsigned int num_tiles_x = (WINDOW_WIDTH - (TEXTURE_SIZE * 8)) / TEXTURE_SIZE;
    const unsigned int num_tiles_y = WINDOW_HEIGHT / TEXTURE_SIZE;
    const unsigned int num_tiles_total = num_tiles_x * num_tiles_y;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "[Untitled game]");
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    // define the level with an array of tile indices

    // create the tilemap from the level definition
    VertexMap map;
    if (!map.loadMap(root_path + "share/textures/map_tiles32.png", root_path + "share/sprites/cursor.png",
            sf::Vector2u(TEXTURE_SIZE, TEXTURE_SIZE), num_tiles_x, num_tiles_y))
        return -1;

    // Cursor
    Cursor cur("./share/sprites/cursor.png", 0, 0);

	// add background music (stream directly from music file)
	sf::Music music;
	if(!music.openFromFile(root_path + "share/audio/BattleTheme.wav")){
		std::cout << "Error: backgound music." << std::endl;
		return -1;
	}
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
	sidebar.createStat(window.getSize().x, window.getSize().y, root_path + "share/resources/ALGER.ttf");

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event)) {
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
							if (cur.getSprite().getPosition().x < 992)
								cur.moveSprite(TEXTURE_SIZE, 0);
							break;
							
						case sf::Keyboard::A:  // Left
							if (cur.getSprite().getPosition().x > 0)
								cur.moveSprite(-TEXTURE_SIZE, 0);
							break;
							
						case sf::Keyboard::W: // UP
							if (cur.getSprite().getPosition().y > 0)
								cur.moveSprite(0, -TEXTURE_SIZE);
							break;
							
						case sf::Keyboard::S: // DOWN
							if (cur.getSprite().getPosition().y < 672)
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
					if(event.key.code == sf::Mouse::Left)
						std::cout << "Mouse left button pressed" << std:: endl;
					break;
			}
			if(event.type == sf::Event::JoystickMoved)  // Controller input events
			{
					// Get direction of D pad press
					int p_x = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX);
					int p_y = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY);
						// Down
					if (p_y > 0) {
						if (cur.getSprite().getPosition().y < 672)
							cur.moveSprite(0, TEXTURE_SIZE);
					}
					// Up
					else if (p_y < 0) {
						if (cur.getSprite().getPosition().y > 0)
							cur.moveSprite(0, -TEXTURE_SIZE);
					}
					// Left
					else if (p_x < 0) {
						if (cur.getSprite().getPosition().x > 0)
							cur.moveSprite(-TEXTURE_SIZE, 0);
					}
					// Right
					else if (p_x > 0) {
						if (cur.getSprite().getPosition().x < 992)
							cur.moveSprite(TEXTURE_SIZE, 0);
					}
					std::cout << "(" << cur.getSprite().getPosition().x << "," << cur.getSprite().getPosition().y << std::endl;
            }
			///std::cout << sf::Mouse::getPosition(window).x << std::endl;
		}
        // Refresh screen
        window.clear();
        window.draw(map);
        window.draw(cur.getSprite());
        window.draw(sidebar);
		sidebar.drawStat(window);
        window.display();
    }
    return 0;
}