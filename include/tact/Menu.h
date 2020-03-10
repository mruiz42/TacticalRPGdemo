// Menu.cpp
// Created by michael on 1/28/20.
//

#ifndef CIS29GROUP2GAME_MENU_H
#define CIS29GROUP2GAME_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <SFML/System/Time.hpp>

namespace tact {
    class Menu;
}

class Menu : public sf::Drawable {
private:
    int selection;
    sf::Font font;
    std::vector<sf::Text> text;
public:
    float width;
    float height;
    Menu(float w, float h);
    Menu(std::string);
    ~Menu();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void move_up();
    void move_down();
    int get_selection(){return selection;}
    void move_left();
    void move_right();
    void set_one_text_color(sf::Color, int);
    void set_selection_text_color(sf::Color);
    void set_all_text_color(sf::Color color);

    void toggle_selection();

    void turn_on();

    void turn_off();
};
#endif //CIS29GROUP2GAME_MENU_H
