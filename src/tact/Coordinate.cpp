//
// Created by michael on 2/20/20.
//

#include "../../include/tact/Coordinate.h"
//void Coordinate::set_coordinate(int x, int y) {
//    this->x = x;
//    this->y = y;
//}
//
//void Coordinate::set_coordinate(Coordinate& coordinate){ // Should this be a copy constructor?
//    this->x = coordinate.x;
//    this->y = coordinate.y;
//}
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

Coordinate* Coordinate::get_coordinate() {
    return this;
}
int Coordinate::get_x() {
    return this->x;
}
int Coordinate::get_y() {
    return this->y;
}