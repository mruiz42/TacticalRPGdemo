//
// Created by michael on 2/6/20.
//

#ifndef CIS29GROUP2GAME_CONTROLLER_H
#define CIS29GROUP2GAME_CONTROLLER_H
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Joystick.hpp>
#include "../../include/tact/Cursor.h"
#include "../../include/tact/Game.h"

// This class will be used to take user input only when a player's turn is active
class Controller {
private:
    sf::Joystick js;
    bool is_active;
public:
    sf::Joystick& get_js() { return this->js; }
    void set_js(sf::Joystick& js);
    void poll(sf::Event&, Cursor& ) const;
    Controller();
};



#endif //CIS29GROUP2GAME_CONTROLLER_H
