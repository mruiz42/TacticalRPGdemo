#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "../include/tact/VertexMap.h"
#include <string>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
const std::string root_path = "./";    // Linux
// Can someone make a standard windows path that will work?
// const std::string root_path = "C:/";    // Windows
int main()
{
    sf::Vertex vertex;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tilemap");
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    // define the level with an array of tile indices
    int level[220] = {};
    for (int i = 0; i < 220; i++)
        level[i] = 1    ;
    // create the tilemap from the level definition
    VertexMap map;
    if (!map.loadMap(root_path + "share/textures/map_tiles32.png", sf::Vector2u(64, 64), level,
            20, 11))
        return -1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}