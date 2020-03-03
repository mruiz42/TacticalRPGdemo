//
// Created by michael on 2/7/20.
//

#include "../../include/tact/Exception.h"

Exception::Exception()
{
    
    if (!font.loadFromFile(exception_path))
    {
        std::cout << "Couldn't load exception_path\n";
    }
    text.setFont(font);
    text.setString("Can't move here.");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color(255,255,255,0));
    
    
}

sf::Text Exception::returnText()
{
    return text;
}

void Exception::draw(sf::RenderTarget& target, sf::RenderStates states) const {}

void Exception::showExcept()
{
    text.setFillColor(sf::Color(255,255,255));
    text.setOutlineColor(sf::Color(0,0,0));
    text.setOutlineThickness(5);
    
}

void Exception::hideExpect()
{
    text.setFillColor(sf::Color(255,255,255,0));
    text.setOutlineThickness(0);
}

void Exception::shift(sf::Vector2f input)
{
    input.y -=25;
    input.x -=32;
    text.setPosition(input);
}