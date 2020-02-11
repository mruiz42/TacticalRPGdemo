//
// Created by michael on 1/28/20.
//

#include "../../include/tact/Menu.h"

#include <iostream>
Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("./bin/Arial.ttf"))
    {
        //handle error
        std::cout<<"Error"<<std::endl;
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2+10, height/(MAX_NUMBER_OF_ITEMS+1)*1)); // divide by 2 so itll be centered, also height will be centered

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::Black);
    menu[1].setString("Credits");
    menu[1].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*2)); // divide by 2 so itll be centered, also height will be centered

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::Black);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*3)); // divide by 2 so itll be centered, also height will be centered

    selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    sf::Texture texture;
    texture.loadFromFile("./bin/NEW_menu.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(width/2, height/2));
    window.draw(sprite);
    for(int i = 0;i<MAX_NUMBER_OF_ITEMS;i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::moveUp()
{
    if(selectedItemIndex - 1 >=0)
    {
        menu[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}