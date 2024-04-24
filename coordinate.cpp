#include "coordinate.h"

//Set the x and y coordinates to zero
Coordinate::Coordinate() {
    x = 0;
    y = 0;
}

//Set the x and y coordiantes to the specified parameters
Coordinate::Coordinate(int x_cor, int y_cor){
    x = x_cor;
    y = y_cor;
}

//Returns the x value of the coordinate
double Coordinate::getX() const{
    return x;
}

//Returns the y value of the coordinate
double Coordinate::getY() const{
    return y;
}

//Sets x to the specified value
void Coordinate::setX(double x_cor){
    x = x_cor;
}

//Sets y to the specified value
void Coordinate::setY(double y_cor){
    y = y_cor;
}
