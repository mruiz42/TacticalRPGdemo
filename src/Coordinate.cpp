//
// Created by michael on 2/20/20.
//

#include "../include/Coordinate.h"

void Coordinate::set_coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}

Coordinate::Coordinate(const Coordinate& coordinate) { 
    this->x = coordinate.x;
    this->y = coordinate.y;
}

void Coordinate::set_coordinate(Coordinate coordinate) {
    this->x = coordinate.x;
    this->y = coordinate.y;
}

std::ostream& operator<< (std::ostream& out, const Coordinate& coordinate){
    out << "(" + std::to_string(coordinate.get_x()) + "," + std::to_string(coordinate.get_y()) + ")" << std::endl;
    return out;
}

Coordinate Coordinate::operator - (const Coordinate& right) {
    Coordinate temp(this->get_x()-right.get_x(), this->get_y()-right.get_y());
    return temp;
}

bool Coordinate::operator == (const Coordinate& right) {
    return this->get_x() == right.get_x() && this->get_y() == right.get_y();
}
