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
    text.setColor(sf::Color(255,255,255,0));
    
    
}

sf::Text Exception::returnText()
{
    return text;
}

void Exception::draw(sf::RenderTarget& target, sf::RenderStates states) const {}

void Exception::showExcept()
{
    text.setColor(sf::Color(255,255,255));
    text.setOutlineColor(sf::Color(0,0,0));
    text.setOutlineThickness(5);
    
}

void Exception::hideExpect()
{
    text.setColor(sf::Color(255,255,255,0));
    text.setOutlineThickness(0);
}

void Exception::shift(float x,float y)
{
    y -=25;
    x -=32;
    text.setPosition(sf::Vector2f(x,y));
}