//
// Created by michael on 1/21/20.
//

#ifndef CIS29GROUP2GAME_FORTRESS_H
#define CIS29GROUP2GAME_FORTRESS_H


class Fortress {
private:
    unsigned int hit_points;
public:
    unsigned int get_hit_points() { return this->hit_points; }
    void set_hit_points(unsigned int hit_points) { this->hit_points = hit_points; }
};


#endif //CIS29GROUP2GAME_FORTRESS_H
