// Menu.cpp
// Created by michael on 1/28/20.
//

#ifndef CIS29GROUP2GAME_MENU_H
#define CIS29GROUP2GAME_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
class Menu : public sf::Drawable {
public:
    float width;
    float height;
    Menu(float w, float h);
    Menu(std::string);
    ~Menu();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void moveUp();
    void moveDown();
    int getSelectedIdx(){return selectedItemIndex;}
private:
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> text;
};
#endif //CIS29GROUP2GAME_MENU_H
