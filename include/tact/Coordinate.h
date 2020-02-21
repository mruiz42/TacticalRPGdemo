//
// Created by michael on 2/20/20.
//

#ifndef CIS29GROUP2GAME_COORDINATE_H
#define CIS29GROUP2GAME_COORDINATE_H
#include <iostream>

class Coordinate {
protected:
    int x;
    int y;
public:
    Coordinate() = default;
    Coordinate(const Coordinate&);
    Coordinate(int x, int y) : x(x), y(y) {}
    void set_coordinate(int,int);
    void set_coordinate(Coordinate);
    void set_x(int x);
    void set_y(int y);

    Coordinate& get_coordinate();
    Coordinate& get_tile_coordinate();
    int get_x() const;
    int get_y() const;
    friend std::ostream& operator<< (std::ostream& out, const Coordinate& coordinate);
};


#endif //CIS29GROUP2GAME_COORDINATE_H
