#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "../include/tact/VertexMap.h"
#include <string>
const std::string root_path = "../";    // Linux
// Can someone make a standard windows path that will work?
// const std::string root_path = "C:/";    // Windows
int main()
{
    sf::Vertex vertex;
    sf::RenderWindow window(sf::VideoMode(256, 256), "Tilemap");
    // define the level with an array of tile indices
    const int level[] = {
                    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
                    1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
                    0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
                    2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
                    0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
            };

    // create the tilemap from the level definition
    VertexMap map;
    if (!map.loadMap(root_path + "share/textures/map_tiles.png", sf::Vector2u(16, 16), level, 16, 16))
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
        window.display();
    }

    return 0;
}