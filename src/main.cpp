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
    sf::RenderWindow window(sf::VideoMode(640, 360), "Tilemap");
    window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
    // define the level with an array of tile indices
    const int level[] = {
                      4,  0,  0,  0,  0,  0, 34,  7,  7,  7,  7,  7,  7,  7,  7, 53,
                      0, 34,  7,  7,  7,  7, 50,  0,  0,  0,  0,  2,  0,  0,  0,  0,
                      0,  8,  0,  0,  0,  0,  0,  0,  9, 54, 54, 54, 54, 54, 54, 54,
                      0, 38,  0,  0,  2,  0,  9, 54, 41,  0,  4,  4,  4,  0,  0,  0,
                      0, 49, 35,  0,  9, 54, 41,  0,  0,  0,  4,  4,  4,  2,  0,  0,
                      0,  0,  8,  0, 55,  0,  2,  2,  0,  0,  4,  4,  4,  4,  2,  0,
                      2,  0,  8,  0, 55,  0,  2,  2,  2,  0,  4,  4,  4,  4,  4,  4,
                      0,  0, 51,  0, 55,  2,  2,  2,  0,  0,  0,  0,  4,  4,  4,  4
            };

    // create the tilemap from the level definition
    VertexMap map;
    if (!map.loadMap(root_path + "share/textures/map_tiles3.png", sf::Vector2u(16, 16), level, 16, 8))
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