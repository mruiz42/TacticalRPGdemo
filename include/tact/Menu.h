// Menu.cpp
// Created by michael on 1/28/20.
//

#ifndef CIS29GROUP2GAME_MENU_H
#define CIS29GROUP2GAME_MENU_H
#include "SFML/Audio/Sound.hpp"
#include "SFML/Graphics.hpp"
class Menu {
private:
    unsigned int width;
    unsigned int height;
    Menu(const unsigned int w, const unsigned int h);
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getSelectedIdx();
    void makeMenu();
};
#endif //CIS29GROUP2GAME_MENU_H
