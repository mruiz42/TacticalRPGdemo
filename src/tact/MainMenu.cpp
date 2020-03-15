//
// Created by michael on 1/28/20.
//

#include "../../include/tact/MainMenu.h"
//#include "../../include/tact/Particle.h"
#include <sstream>
#include<SFML/Graphics.hpp>


#include <iostream>
MainMenu::MainMenu(float width, float height)
{
    if(!font.loadFromFile("share/resources/PressStart2P-Regular.ttf"))
    {
        //handle error
        std::cout<<"Error"<<std::endl;
    }

    main_menu[0].setFont(font);
    main_menu[0].setFillColor(sf::Color::Red);
    main_menu[0].setString("Play");
    main_menu[0].setPosition(sf::Vector2f(width-400, height/(MAX_NUMBER_OF_ITEMS+1))); // divide by 2 so itll be centered, also height will be centered

    main_menu[1].setFont(font);
    main_menu[1].setFillColor(sf::Color::White);
    main_menu[1].setString("Instructions");
    main_menu[1].setPosition(sf::Vector2f(width-400, height/(MAX_NUMBER_OF_ITEMS+1)*2)); // divide by 2 so itll be centered, also height will be centered

    main_menu[2].setFont(font);
    main_menu[2].setFillColor(sf::Color::White);
    main_menu[2].setString("Exit");
    main_menu[2].setPosition(sf::Vector2f(width-400, height/(MAX_NUMBER_OF_ITEMS+1)*3)); // divide by 2 so itll be centered, also height will be centered

    instructions[0].setFont(font);
    instructions[0].setFillColor(sf::Color::Red);
    instructions[0].setString("Controls(Keyboard/Controller):");
    instructions[0].setPosition(sf::Vector2f(0,0));

    //inc by 30
    instructions[1].setFont(font);
    instructions[1].setFillColor(sf::Color::White);
    instructions[1].setString("WASD/D-pad: move\nEnter/A:select and move\nQ/L2:automatically go to character\nBackspace/B:Undo\nDash:volume down\nEqual:volume up");
    instructions[1].setPosition(sf::Vector2f(30, 30)); // divide by 2 so itll be centered, also height will be centered


    instructions[2].setFont(font); 
    instructions[2].setFillColor(sf::Color::Red);
    instructions[2].setString("Instructions:");
    instructions[2].setPosition(sf::Vector2f(0, 220)); // divide by 2 so itll be centered, also height will be centered

    instructions[3].setFont(font); 
    instructions[3].setFillColor(sf::Color::White);
    instructions[3].setString("Select a sprite and place it within\nmovement range\nEach sprite moves once per turn\nGoal: Eliminate opposing characters");
    instructions[3].setPosition(sf::Vector2f(30, 260)); // divide by 2 so itll be centered, ach character movesalso height will be centered

    instructions[4].setFont(font); 
    instructions[4].setFillColor(sf::Color::White);
    instructions[4].setString("Press Return to go back to the main menu");
    instructions[4].setPosition(sf::Vector2f(0, 400)); // divide by 2 so itll be centered, ach character movesalso height will be centered

    selectedItemIndex = 0;
}

MainMenu::~MainMenu()
{}

void MainMenu::draw(sf::RenderWindow &window)
{

    /*
    sf::Texture texture;
    texture.loadFromFile("share/textures/NEW_main_menu.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(width/2, height/2));
    window.draw(sprite);
    */
    for(auto i = 0;i<MAX_NUMBER_OF_ITEMS;i++)
    {
        window.draw(main_menu[i]);
    }


}

void MainMenu::move_up()
{
    if(selectedItemIndex - 1 >=0)
    {
        main_menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        main_menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MainMenu::move_down()
{
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        main_menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        main_menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MainMenu::draw_instruction(sf::RenderWindow &window)
{
    for(auto i = 0;i<5;i++)
    {
        window.draw(instructions[i]);
    }

}