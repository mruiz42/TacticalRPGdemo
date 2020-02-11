//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Sidebar.h"

Sidebar::Sidebar(std::string filename){
    if(!this->background.loadFromFile(filename, sf::IntRect(0,0,256,704))) {
        std::cout << "Could not open: " + filename << std::endl;
    }
    sidebar.setTexture(background);
    sidebar.setPosition(1024,0);

}

void Sidebar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();
    // apply the tileset texture
    states.texture = &background;
    // draw the vertex array
    target.draw(sidebar, states);
}