#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "../include/tact/VertexMap.h"
#include <string>
#include "../include/tact/Knight.h"
#include "../include/tact/Character.h"
#include <iostream>
#include "../include/tact/Cursor.h"
#include "../include/tact/Sidebar.h"
#include "../include/tact/Character.h"
#include "../include/tact/Music.h"
#include "../include/tact/Sound.h"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 704
#define TEXTURE_SIZE 32


const std::string fontFileName = "share/resources/PressStart2P-Regular.ttf";

const std::string root_path = "./";    // Linux
// Can someone make a standard windows path that will work?
// const std::string root_path = "C:/";    // Windows

///#pragma once


int main()
{
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
	
	// Music menuMusic("./share/audio/Vanadiel_March.wav");
	Music gameMusic("./share/audio/BattleTheme.wav");
	Sound adjustVolumeSound("./share/audio/volume_change.wav");
	// credit to https://www.noiseforfun.com/2012-sound-effects/menu-05-a/
	
    std::cout << sf::Joystick::getButtonCount(0) << std::endl;
	
	Character c1;
	c1.set_hit_points(100);
	
	
	/* turn loop
	while( (at least one character of player one HP positive) 
		   && (at least one character of player two HP positive))
	{
		player one's turn
		player two's turn
	}
	*/
	
    while (window.isOpen())
    {
        /// display character's info on sidebar
		Sidebar sidebar(root_path + "share/textures/sidebar_background.png");
		sidebar.createStat(WINDOW_WIDTH, WINDOW_HEIGHT, root_path + fontFileName);
		sidebar.setStats(c1, window.getSize().x, window.getSize().y, root_path + fontFileName);
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
							gameMusic.lowerVolume();
							adjustVolumeSound.lowerVolume();
							break;
						case sf::Keyboard::Key::Equal:  // Volume Up
							gameMusic.raiseVolume();
							adjustVolumeSound.raiseVolume();
							break;
					}

				case sf::Event::MouseButtonPressed:  // Mouse events
					if(event.key.code == sf::Mouse::Left){
						int currentHP = c1.get_hit_points() - 1;
					    c1.set_hit_points(currentHP);
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
			std::cout << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << std::endl;
		}
		
        // Refresh screen
        window.clear();
        window.draw(map);
        window.draw(cur.getSprite());
        window.draw(sidebar);
		sidebar.drawStat(window);
		sidebar.drawStats(window);
        window.display();
    }
    return 0;
}