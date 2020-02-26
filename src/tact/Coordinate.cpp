//
// Created by michael on 2/20/20.
//

#include "../../include/tact/Coordinate.h"
//void Coordinate::set_coordinate(int x, int y) {
//    this->x = x;
//    this->y = y;
//}
//

Coordinate::Coordinate(const Coordinate& coordinate){ // Should this be a copy constructor?
    this->x = coordinate.x;
    this->y = coordinate.y;
}

void Coordinate::set_x(int x) {
    this->x = x;
}

void Coordinate::set_y(int y) {
    this->y = y;
}

void Coordinate::set_coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}

void Coordinate::set_coordinate(Coordinate coordinate) {
    this->x = coordinate.x;
    this->y = coordinate.y;
}


int Coordinate::get_x() const {
    return this->x;
}

int Coordinate::get_y() const {
    return this->y;
}

// // gets map coordiante so char can walk
float Coordinate::get_map_x() const {
     return (this->x)*32.0f;
 }

// //gets map coordinate so char can walk
float Coordinate::get_map_y() const {
     return (this->y)*32.0f;
}



std::ostream& operator<< (std::ostream& out, const Coordinate& coordinate){
    out << "(" + std::to_string(coordinate.get_x()) + "," + std::to_string(coordinate.get_y()) + ")" << std::endl;
    return out;
}