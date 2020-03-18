#include "../include/tact/Game.h"
#include "../include/tact/MainMenu.h"

const std::string music_menu_path = "./share/audio/Vanadiel_March.wav";

void main_menu(sf::RenderWindow& window,sf::Vector2u &screenDimensions);

int main(){
    // Create window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tactical RPG demo");
    sf::Event Event;
    sf::Vector2u dimmesions(WINDOW_WIDTH, WINDOW_HEIGHT);
    main_menu(window,dimmesions);
    window.clear();
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    tact::Game game;
    game.play_game(window);
    return 0;
}

void main_menu(sf::RenderWindow& window,sf::Vector2u &screenDimensions){
    MainMenu main_menu(window.getSize().x, window.getSize().y);
	sf::Music gameMusic;
    if(!gameMusic.openFromFile(music_menu_path)){
        std::cout << "Error: could not load file" << music_path << std::endl;
        exit(-1);
    }
    gameMusic.setVolume(30);
    gameMusic.play();
    gameMusic.setLoop(true);
    window.clear();
    while (window.isOpen()){
        top:
        window.clear();
        main_menu.draw(window);
        window.display();
        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){
				case sf::Event::KeyReleased:
					switch(event.key.code){
						case sf::Keyboard::W:
						case sf::Keyboard::Up:
							main_menu.move_up();
							break;

						case sf::Keyboard::Down:
						case sf::Keyboard::S:
							main_menu.move_down();
							break;
						case sf::Keyboard::Return:
							switch(main_menu.get_selection_index()){
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
										while (window.pollEvent(event)){
											/* code */
											switch (event.type){
												case sf::Event::KeyReleased:
													switch(event.key.code){
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