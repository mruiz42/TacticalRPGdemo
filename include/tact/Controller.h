//
// Created by michael on 2/20/20.
//

#ifndef CIS29GROUP2GAME_CONTROLLER_H
#define CIS29GROUP2GAME_CONTROLLER_H
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Joystick.hpp>
#include "Cursor.h"
#include <iostream>
#define TEXTURE_SIZE 32

class Controller {
private:
    sf::Joystick js;
    bool is_active;
public:
    sf::Joystick& get_js() { return this->js; }
    void set_js(sf::Joystick& js);
    void poll(sf::Event&, Cursor&, int) const;

    Controller() {}
};


#endif //CIS29GROUP2GAME_CONTROLLER_H
