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
#include "../include/tact/CharacterMap.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 704
#define TEXTURE_SIZE 32

const int HP_MAX = 200;
const int HP_MIN = 0;
const int HP_RAISE = 5;
const int HP_DROP = 10;
static int HP = 100;
const std::string fontFileName = "share/resources/PressStart2P-Regular.ttf";

const std::string root_path = "./";    // Linux
// Can someone make a standard windows path that will work?
// const std::string root_path = "C:/";    // Windows

#define MAX_NUM_SIDEBAR_ITEMS 3
class Sidekick
{
public:
	Sidekick(float width, float height)
	{
		if(!font.loadFromFile(root_path + "share/resources/ChunkyDunk.ttf"))
		{ exit(101); }

		sidekick[0].setFont(font);
		sidekick[0].setFillColor(sf::Color::Red);
		sidekick[0].setString("ATTACK");
		sidekick[0].setCharacterSize(32);
        int p0w = 1024 + 256/2 - sidekick[0].getLocalBounds().width/2;
        sidekick[0].setPosition(sf::Vector2f(p0w, 560));

		sidekick[1].setFont(font);
		sidekick[1].setFillColor(sf::Color::White);
		sidekick[1].setString("DEFEND");
		sidekick[1].setCharacterSize(32);
        int p1w = 1024 + 256/2 - sidekick[1].getLocalBounds().width/2;
        sidekick[1].setPosition(sf::Vector2f(p1w, 600));

		sidekick[2].setFont(font);
		sidekick[2].setFillColor(sf::Color::White);
		sidekick[2].setString("MOVE");
		sidekick[2].setCharacterSize(32);
        int p2w = 1024 + 256/2 - sidekick[2].getLocalBounds().width/2;
        sidekick[2].setPosition(sf::Vector2f(p2w, 640));
	}
	~Sidekick(){}

	void draw(sf::RenderWindow &window)
	{
		for(int i =0; i < MAX_NUM_SIDEBAR_ITEMS; i++)
			window.draw(sidekick[i]);
	}
	void MoveUp();
	void MoveDown();
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text sidekick[MAX_NUM_SIDEBAR_ITEMS];
};


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
						sidebar.hp_raise(HP, HP_MAX, HP_RAISE, window.getSize().x, window.getSize().y, root_path + fontFileName, window);
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
    return 0;
}