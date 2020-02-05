#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "../include/tact/VertexMap.h"
#include <string>
#include <iostream>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define TEXTURE_SIZE 32
const std::string root_path = "./";    // Linux
// Can someone make a standard windows path that will work?
// const std::string root_path = "C:/";    // Windows
int main()
{
    const unsigned int num_tiles_x = WINDOW_WIDTH / TEXTURE_SIZE;
    const unsigned int num_tiles_y = WINDOW_HEIGHT / TEXTURE_SIZE;
    const unsigned int num_tiles_total = num_tiles_x * num_tiles_y;
    sf::Vertex vertex;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tilemap");
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    // define the level with an array of tile indices
    int level[num_tiles_x][num_tiles_y] = {};
    for (int i = 0; i < num_tiles_x; i++)
        for (int j = 0; j < num_tiles_y; j++)

        level[i][j] = 1;
    // create the tilemap from the level definition
    VertexMap map;
    if (!map.loadMap(root_path + "share/textures/map_tiles32.png", root_path+"share/sprites/cursor.png",
            sf::Vector2u(TEXTURE_SIZE, TEXTURE_SIZE), level, num_tiles_x, num_tiles_y))
        return -1;

	// add background music (stream directly from music file)
	sf::Music music;
	if(!music.openFromFile(root_path + "share/audio/Vanadiel_March.wav")){
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


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			if (event.type == sf::Event::EventType::KeyPressed){
				// Up and down to control volume
				if (event.key.code == sf::Keyboard::Key::Down){
				  music.setVolume(music.getVolume() - 10);
				  sound.setVolume(sound.getVolume() - 10);
				  sound.play();
				}
				if (event.key.code == sf::Keyboard::Key::Up){
				  music.setVolume(music.getVolume() + 10);
				  sound.setVolume(sound.getVolume() + 10);
				  sound.play();
				  if (music.getVolume() >= 100){
					  music.setVolume(100);
					  sound.setVolume(100);
				  }
				}
			}
		}

        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}