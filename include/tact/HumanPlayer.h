//
// Created by michael on 2/20/20.
//

#ifndef CIS29GROUP2GAME_HUMANPLAYER_H
#define CIS29GROUP2GAME_HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player {
private:
    Controller controller;
public:
    HumanPlayer();
    HumanPlayer(Coordinate);
    ~HumanPlayer();
    Controller& get_controller() { return this->controller;}
    void set_controller(Controller& controller) { this->controller = controller; }
};


#endif //CIS29GROUP2GAME_HUMANPLAYER_H
