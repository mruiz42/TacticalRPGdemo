// Menu.cpp
// Created by michael on 1/28/20.
//

#ifndef CIS29GROUP2GAME_MENU_H
#define CIS29GROUP2GAME_MENU_H

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

#define MAX_NUMBER_OF_ITEMS 3
class Menu {
public:
    float width;
    float height;
    Menu(float w, float h);
    ~Menu();
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getSelectedIdx(){return selectedItemIndex;}
private:
    
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    //void makeMenu();
};
#endif //CIS29GROUP2GAME_MENU_H
