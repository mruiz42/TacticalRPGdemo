//
// Created by michael on 1/28/20.
//

#include "../../include/tact/Menu.h"

using namespace tact;


Menu::Menu(std::string font_filename) {
    if(!font.loadFromFile(font_filename)) {
        std::cout << "Could not open: " + font_filename << std::endl;
    }

    text.resize(4);
    // 0 - MOVE
    text[0].setCharacterSize(24);
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::White);
    text[0].setString("MOVE");
    text[0].setPosition(sf::Vector2f(1054, 512));
    // 1 - WAIT
    text[1].setCharacterSize(24);
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::White);
    text[1].setString("WAIT");
    text[1].setPosition(sf::Vector2f(1180, 512));
    // 2 - ATTACK
    text[2].setCharacterSize(24);
    text[2].setFont(font);
    text[2].setFillColor(sf::Color::White);
    text[2].setString("ATTACK");
    text[2].setPosition(sf::Vector2f(1046, 576));
    // 3 - DEFEND
    text[3].setCharacterSize(24);
    text[3].setFont(font);
    text[3].setFillColor(sf::Color::White);
    text[3].setString("DEFEND");
    text[3].setPosition(sf::Vector2f(1170, 576));

    selection = -1;
}

Menu::~Menu() { }

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i = 0; i < text.size(); i++) {
        target.draw(text[i]);
    }

}

void Menu::move_right() {
    if (selection == 2){
        selection = 3;
    }
    else if (selection == 0){
        selection = 1;
    }

    std::cout << selection << std::endl;

}

void Menu::move_left() {
    if (selection == 1){
        selection = 0;
    }
    else if (selection == 3){
        selection = 2;
    }
    std::cout << selection << std::endl;

}

void Menu::move_up() {
    if (selection == 2){
        selection = 0;
    }
    else if (selection == 3) {
        selection = 1;
    }
    std::cout << selection << std::endl;

}

void Menu::move_down() {
    if (selection == 0){
        selection = 2;
    }
    else if (selection == 1){
        selection = 3;
    }
    std::cout << selection << std::endl;
}

void Menu::set_selection_text_color(sf::Color color){
    sf::Color prev_color = text[selection].getFillColor();
    sf::Clock clock;
    float elapsed = clock.getElapsedTime().asMilliseconds();
    text[selection].setFillColor(color);
}

void Menu::set_one_text_color(sf::Color color, int position){
    text[position].setFillColor(color);
}

void Menu::set_all_text_color(sf::Color color){
    for (auto i = 0; i < text.size(); i++){
        this->text[i].setFillColor(color);
    }
    if (selection <= 3 && selection >= 0) {
        this->text[selection].setFillColor(sf::Color::Red);
    }
}

void Menu::toggle_selection() {
    if (this->selection > 3 || this->selection < 0)
        this->selection = 0;
    else
        this->selection = -1;
}

void Menu::turn_on() {
    this->set_all_text_color(sf::Color::White);
    if (this->selection > 3 || this->selection < 0)
        this->selection = 0;
}

void Menu::turn_off() {
    this->selection = -1;
    this->set_all_text_color(sf::Color(128,128,128, 255));
}
