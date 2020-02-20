//
// Created by michael on 2/20/20.
//

#ifndef CIS29GROUP2GAME_COORDINATE_H
#define CIS29GROUP2GAME_COORDINATE_H


class Coordinate {
private:
    int x;
    int y;
public:
    void set_coordinates(int x, int y);
    void set_coordinates(Coordinate& coordinate);
    void set_x(int x);
    void set_y(int y);

    Coordinate* get_coordinate();
    int get_x();
    int get_y();
};


#endif //CIS29GROUP2GAME_COORDINATE_H
