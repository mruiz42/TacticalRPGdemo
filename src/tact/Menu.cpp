//
// Created by michael on 1/28/20.
//

#include "../../include/tact/Menu.h"

Menu::Menu(std::string font_filename) {
    if(!font.loadFromFile(font_filename)) {
        std::cout << "Could not open: " + font_filename << std::endl;
    }

    text.resize(3);
    text[0].setCharacterSize(24);
    text[0].setFont(font);
    text[0].setColor(sf::Color::White);
    text[0].setString("MOVE");
    text[0].setPosition(sf::Vector2f(1054, 512));

    text[1].setCharacterSize(24);
    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("ATTACK");
    text[1].setPosition(sf::Vector2f(1160, 512));

    text[2].setCharacterSize(24);
    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("DEFEND");
    text[2].setPosition(sf::Vector2f(1046, 576));

    selectedItemIndex = 0;
}

Menu::~Menu() { }

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i = 0;i<text.size();i++) {
        target.draw(text[i]);
    }
}

void Menu::moveUp()
{
    if(selectedItemIndex - 1 >=0)
    {
        text[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if(selectedItemIndex + 1 < text.size())
    {
        text[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        text[selectedItemIndex].setColor(sf::Color::Red);
    }
}