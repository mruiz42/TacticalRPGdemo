//
// Created by michael on 2/20/20.
//

#include "../../include/tact/Controller.h"

void Controller::poll(sf::Event& event, Cursor& cur, int js_id) const {
    if(event.type == sf::Event::JoystickMoved)  // Controller input events
    {
        // Get direction of D pad press
        int p_x = sf::Joystick::getAxisPosition(js_id, sf::Joystick::PovX);
        int p_y = sf::Joystick::getAxisPosition(js_id, sf::Joystick::PovY);
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
//        std::cout << "(" << cur.get_sprite().getPosition().x << "," << cur.get_sprite().getPosition().y << std::endl;
    }
//			std::cout << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << std::endl;
}