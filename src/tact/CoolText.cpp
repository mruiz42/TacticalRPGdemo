//
// Created by michael on 3/2/20.
//

#include "../../include/tact/CoolText.h"

using namespace tact;

CoolText::CoolText(std::string font_path) {
    if (!font.loadFromFile(font_path)) {
        std::cout << "Could not load " <<  font_path << " from file." << std::endl;
    }
    this->text.setFont(font);
    this->text.setOutlineColor(sf::Color::Black);
    this->text.setOutlineThickness(3);
    this->text.setCharacterSize(12);
}

void CoolText::set_position(float x, float y) {
    position = sf::Vector2f(x,y);
    this->text.setPosition(position);
}

void CoolText::set_text(std::string string) {
    this->text.setString(string);
}

void CoolText::start_clock() {
    this->set_clock(sf::Clock());
}

bool CoolText::draw_raising() {
    if (this->clock.getElapsedTime().asMilliseconds() < 1000) {
        this->text.move(0, -0.32);
        return true;
    }
    else
        return false;
}

bool CoolText::draw_centered(){
    if (this->clock.getElapsedTime().asMilliseconds() < 2000) {
        text.setCharacterSize(32);
        text.setColor(sf::Color::White);
        text.setOutlineThickness(4);
        text.setOutlineColor(sf::Color::Black);
        this->set_position(1024/2 - (text.getGlobalBounds().width)/2, 704/2 - (text.getGlobalBounds().height)/2);
        return true;
    }
    else
        return false;
}
