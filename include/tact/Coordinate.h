//
// Created by michael on 2/20/20.
//

#ifndef CIS29GROUP2GAME_COORDINATE_H
#define CIS29GROUP2GAME_COORDINATE_H
#include <iostream>

#define TEXTURE_SIZE 32

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
    int get_x() const;
    int get_y() const;
    float get_map_x() const;
    float get_map_y() const;
    Coordinate operator - (const Coordinate&);
    bool operator == (const Coordinate&);
    friend std::ostream& operator<< (std::ostream& out, const Coordinate& coordinate);
};


#endif //CIS29GROUP2GAME_COORDINATE_H
