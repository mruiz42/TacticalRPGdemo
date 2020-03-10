//
// Created by michael on 3/2/20.
//

#ifndef CIS29GROUP2GAME_COOLTEXT_H
#define CIS29GROUP2GAME_COOLTEXT_H
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <string>

class CoolText {
private:
    sf::Font font;
    sf::Text text;
    sf::Vector2f position;
    sf::Clock clock;
public:
    CoolText(std::string);

    sf::Font get_font() { return this->font; }
    sf::Text get_text() { return this->text; }
    sf::Vector2f get_position() { return this->position; }
    sf::Clock get_clock() { return this->clock; }

    void set_font(sf::Font font) { this->font = font; }
    void set_text(sf::Text text) { this->text = text; }
    void set_position(sf::Vector2f vector) { this->position = position; }
    void set_position(float, float);
    void set_clock(sf::Clock clock) { this->clock = clock; }
    void set_text(std::string string);

    bool draw_raising();

    void start_clock();


    bool draw_centered();
};


#endif //CIS29GROUP2GAME_COOLTEXT_H
