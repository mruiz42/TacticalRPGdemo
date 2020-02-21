//
// Created by michael on 2/21/20.
//

#ifndef CIS29GROUP2GAME_SELECTION_H
#define CIS29GROUP2GAME_SELECTION_H
#include "Character.h"

class Selection {
private:
    Character& selection;
    Character& target;
public:
    Selection();
    Character& get_selection();
    Character& get_target();

    void set_selection(Character& selection);
    void set_target(Character& target);

    void clear();
};


#endif //CIS29GROUP2GAME_SELECTION_H
