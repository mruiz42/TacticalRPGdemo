//
// Created by michael on 1/28/20.
//

#include "../../include/tact/Menu.h"

Menu::Menu(std::string font_filename) {
    if(!font.loadFromFile(font_filename)) {
        std::cout << "Could not open: " + font_filename << std::endl;
    }

    text.resize(4);
    text[0].setCharacterSize(24);
    text[0].setFont(font);
    text[0].setColor(sf::Color::White);
    text[0].setString("MOVE");
    text[0].setPosition(sf::Vector2f(1054, 512));

    text[1].setCharacterSize(24);
    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("WAIT");
    text[1].setPosition(sf::Vector2f(1180, 512));

    text[2].setCharacterSize(24);
    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("ATTACK");
    text[2].setPosition(sf::Vector2f(1046, 576));

    text[3].setCharacterSize(24);
    text[3].setFont(font);
    text[3].setColor(sf::Color::White);
    text[3].setString("DEFEND");
    text[3].setPosition(sf::Vector2f(1170, 576));

    selection = 0;
}

Menu::~Menu() { }

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i = 0;i<text.size();i++) {
        target.draw(text[i]);
    }
}

void Menu::move_right() {
    set_all_text_color(sf::Color::White);
    if (selection == 2){
        selection = 3;
    }
    else if (selection == 0){
        selection = 1;
    }

    text[selection].setColor(sf::Color::Red);
    std::cout << selection << std::endl;

}

void Menu::move_left() {
    set_all_text_color(sf::Color::White);
    if (selection == 1){
        selection = 0;
    }
    else if (selection == 3){
        selection = 2;
    }
    text[selection].setColor(sf::Color::Red);
    std::cout << selection << std::endl;

}

void Menu::move_up() {
    set_all_text_color(sf::Color::White);
    if (selection == 2){
        selection = 0;
    }
    else if (selection == 3) {
        selection = 1;
    }
    text[selection].setColor(sf::Color::Red);
    std::cout << selection << std::endl;

}

void Menu::move_down() {
    set_all_text_color(sf::Color::White);
    if (selection == 0){
        selection = 2;
    }
    else if (selection == 1){
        selection = 3;
    }
    text[selection].setColor(sf::Color::Red);
    std::cout << selection << std::endl;
}

void Menu::set_selection_text_color(sf::Color color){
    sf::Color prev_color = text[selection].getColor();
    sf::Clock clock;
    float elapsed = clock.getElapsedTime().asMilliseconds();
    text[selection].setColor(color);
//    while (elapsed < 2) {
//        std::cout << elapsed << " ";
//        text[selection].setColor(color);
//        elapsed = clock.getElapsedTime().asSeconds();
//    }
//    text[selection].setColor(prev_color);
}

void Menu::set_one_text_color(sf::Color color, int position){
    text[position].setColor(color);
    // wait
}

void Menu::set_all_text_color(sf::Color color){
    for (auto i = 0; i < text.size(); i++){
        text[i].setColor(color);
    }
}