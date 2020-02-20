//
// Created by michael on 2/20/20.
//

#ifndef CIS29GROUP2GAME_COORDINATE_H
#define CIS29GROUP2GAME_COORDINATE_H


class Coordinate {
public:
    int x;
    int y;
    void set_coordinate(int,int);
    void set_x(int x);
    void set_y(int y);

    Coordinate* get_coordinate();
    int get_x();
    int get_y();
};


#endif //CIS29GROUP2GAME_COORDINATE_H
