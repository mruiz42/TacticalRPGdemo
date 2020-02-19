#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "../include/tact/VertexMap.h"
#include <string>
#include "../include/tact/Menu.h"
#include <iostream>
#include "../include/tact/Particle.h"

using std::cout;
using std::endl;


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
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Menu");
    Menu menu(window.getSize().x,window.getSize().y);
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    // define the level with an array of tile indices
    int level[num_tiles_total] = {};
    for (int i = 0; i < num_tiles_total; i++)
        level[i] = 1;
    // create the tilemap from the level definition
    VertexMap map;
    if (!map.loadMap(root_path + "share/textures/map_tiles32.png", root_path+"share/sprites/cursor.png",
            sf::Vector2u(TEXTURE_SIZE, TEXTURE_SIZE), level, num_tiles_x, num_tiles_y))
        return -1;

    ParticleSystem particles(1000);
    sf:: Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.moveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.moveDown();
                    break;
                    
                case sf::Keyboard::Return:
                    switch(menu.getSelectedIdx())
                    {
                        case 0:
                            std::cout<<"Play button has been pressed"<<std::endl;
                            break;
                        case 1:
                            std::cout<<"Option button has been pressed"<<std::endl;
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
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        particles.setEmitter(window.mapPixelToCoords(mouse));
        //update it
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);
        //draw it
        window.clear();
        window.draw(particles);
        
        menu.draw(window);
    
        window.display();
     
    }
    //window.clear();

    return 0;
}