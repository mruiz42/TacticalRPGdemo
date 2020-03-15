#include "../include/tact/Game.h"
#include "../include/tact/MainMenu.h"
#include "../include/Music.h"
#include "../include/Sound.h"

//const int HP_MAX = 200;
//const int HP_MIN = 0;
//const int HP_RAISE = 5;
//const int HP_DROP = 10;
//static int HP = 100;

const std::string music_path = "./share/audio/BattleTheme.wav";
const std::string music_menu_path = "./share/audio/Vanadiel_March.wav";
const std::string sound_path = "./share/audio/volume_change.wav";

void main_menu(sf::RenderWindow& window,sf::Vector2u &screenDimensions);

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tactical RPG demo");
    sf::Event Event;
    sf::Vector2u dimmesions(WINDOW_WIDTH, WINDOW_HEIGHT);
    main_menu(window,dimmesions);
    window.clear();
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    tact::Game game;
	Music gameMusic(music_path);
	Sound adjustVolumeSound(sound_path);
    game.play_game(window);
    return 0;
}

void main_menu(sf::RenderWindow& window,sf::Vector2u &screenDimensions)
{
    MainMenu main_menu(window.getSize().x, window.getSize().y);
	Music gameMusic(music_menu_path);
	Sound adjustVolumeSound(sound_path);
    window.clear();
    while (window.isOpen())
    {
        top:
        window.clear();
        main_menu.draw(window);
        window.display();
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::W:
                case sf::Keyboard::Up:
                    main_menu.move_up();
                    break;

                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    main_menu.move_down();
                    break;

				case sf::Keyboard::Key::Dash: // Volume Down
					gameMusic.lowerVolume();
					adjustVolumeSound.lowerVolume();
					break;
				case sf::Keyboard::Key::Equal:  // Volume Up
					gameMusic.raiseVolume();
					adjustVolumeSound.raiseVolume();
					break;
					
                case sf::Keyboard::Return:
                    switch(main_menu.get_selection_index())
                    {
                        case 0:
                            std::cout<<"Play button has been pressed"<<std::endl;
                            return;
                            break;
                        case 1:
                            std::cout<<"Instruction button has been pressed"<<std::endl;
                            while (window.isOpen()){
                                window.clear();
                                main_menu.draw_instruction(window);
                                window.display();
                                while (window.pollEvent(event))
                                {
                                    /* code */
                                    switch (event.type)
                                    {
                                    case sf::Event::KeyReleased:
                                        switch(event.key.code)
                                        {
                                        case sf::Keyboard::Return: goto top;
                                            break;
                                        }
                                    }
                                }

                            }
                            break;
                        case 2:
                            std::cout<<"Exit button has been pressed"<<std::endl;
                            window.close();
                            break;
                    }
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }


        }

    }
}