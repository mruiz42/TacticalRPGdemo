//
// Created by michael on 2/20/20.
//

#include "../../include/tact/Controller.h"

void Controller::move_cursor_poll(sf::Event& event, Cursor& cur, int id) const {
    if(event.type == sf::Event::JoystickMoved) {  // Controller input events
        // Get direction of D pad press
        int p_x = sf::Joystick::getAxisPosition(id, sf::Joystick::PovX);
        int p_y = sf::Joystick::getAxisPosition(id, sf::Joystick::PovY);
        std::cout << p_x << " " << p_y << std::endl;
        // Down
        if (p_y > 0) {
            if (cur.get_sprite().getPosition().y < 672)
                cur.moveSprite(0, TEXTURE_SIZE);
        }
            // Up
        else if (p_y < 0) {
            if (cur.get_sprite().getPosition().y > 0)
                cur.moveSprite(0, -TEXTURE_SIZE);
        }
            // Left
        else if (p_x < 0) {
            if (cur.get_sprite().getPosition().x > 0)
                cur.moveSprite(-TEXTURE_SIZE, 0);
        }
            // Right
        else if (p_x > 0) {
            if (cur.get_sprite().getPosition().x < 992)
                cur.moveSprite(TEXTURE_SIZE, 0);
        }
    }
}

int Controller::menu_poll(sf::Event& event, Sidebar& sidebar, int id, bool menu_selected, bool unit_selected) {
    if(event.type == sf::Event::JoystickMoved) { // Controller input events
        // Get direction of D pad press
        int p_x = sf::Joystick::getAxisPosition(id, sf::Joystick::PovX);
        int p_y = sf::Joystick::getAxisPosition(id, sf::Joystick::PovY);

        // Down
        if (p_y > 0) {
            sidebar.get_menu().move_down();
            return -1;
        }

            // Up
        else if (p_y < 0) {
            sidebar.get_menu().move_up();
            return -1;
        }

            // Left
        else if (p_x < 0) {
            sidebar.get_menu().move_left();
            return -1;
        }

            // Right
        else if (p_x > 0) {
            sidebar.get_menu().move_right();
            return -1;
        }


    }
    else if(event.type == sf::Event::JoystickButtonPressed) {
        if (sf::Joystick::isButtonPressed(id, 0)) {
            sidebar.get_menu().set_selection_text_color(sf::Color::Cyan);
            return sidebar.get_menu().get_selection();
        }
        else if (sf::Joystick::isButtonPressed(id, 1)) {
            sidebar.get_menu().set_selection_text_color(sf::Color::Red);
            sidebar.get_menu().set_all_text_color(sf::Color::White);
            menu_selected = false;
            unit_selected = false;
            return -1;
        }
    }



}


//    switch (event.e) {
//        case sf::Keyboard::Key::D:   // Right
//            this->sidebar.get_menu().move_right();
//            return -1;
//
//        case sf::Keyboard::Key::A:  // Left
//            this->sidebar.get_menu().move_left();
//            return -1;
//
//        case sf::Keyboard::Key::W: // UP
//            this->sidebar.get_menu().move_up();
//            return -1;
//
//        case sf::Keyboard::Key::S: // DOWN
//            this->sidebar.get_menu().move_down();
//            return -1;
//
//        case sf::Keyboard::Key::Return: {         // Pick up
//            this->sidebar.get_menu().set_selection_text_color(sf::Color::Cyan);
//            return sidebar.get_menu().get_selection();
//        }
//
//        case sf::Keyboard::Key::BackSpace: {
//            this->sidebar.get_menu().set_selection_text_color(sf::Color::Red);
//            sidebar.get_menu().set_all_text_color(sf::Color::White);
//            menu_selected = false;
//            unit_selected = false;
//            return -1;
//        }
//    }
