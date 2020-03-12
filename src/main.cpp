#include "../include/tact/Game.h"
#include "../include/tact/Main_Menu.h"
//const int HP_MAX = 200;
//const int HP_MIN = 0;
//const int HP_RAISE = 5;
//const int HP_DROP = 10;
//static int HP = 100;

void main_menu(sf::RenderWindow& window,sf::Vector2u &screenDimensions);
int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "[Untitled game]");
    sf::Event Event;
    sf::Vector2u dimmesions(WINDOW_WIDTH, WINDOW_HEIGHT);

    main_menu(window,dimmesions);
    window.clear();
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    Game game;
    game.play_game(window);
    return 0;
}

void main_menu(sf::RenderWindow& window,sf::Vector2u &screenDimensions)
{

    Main_Menu main_menu(window.getSize().x,window.getSize().y);
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
                    main_menu.moveUp();
                    break;

                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    main_menu.moveDown();
                    break;
                    
                case sf::Keyboard::Return:
                    switch(main_menu.getSelectedIdx())
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