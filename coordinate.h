#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
private:
    double x;
    double y;

public:
    Coordinate();
    Coordinate(int x_cor, int y_cor);
double  getX() const;
double getY() const;
void setX(double x_cor);
void setY(double y_cor);
};

#endif // COORDINATE_H
