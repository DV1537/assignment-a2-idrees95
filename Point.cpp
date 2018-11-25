#include<string>
#include <cmath>
using namespace std;
#include "Shape.h"
#include "Point.h"

Point::Point(double* vertices) 
{
    this->vertices = vertices;
}

double Point::area()
{
    return -1;
}

std::string Point::getType() const
{
    return "Point";
}

double Point::circumference()
{
    return 0;
}

bool Point::isConvex()
{
    //any shape less than 3 vertices is convex
    return false;
}

double* Point::position()
{
    return vertices;
}

double Point::distance(Shape *s)
{
    double thisX = this->position()[0];
    double thisY = this->position()[1];
    double otherX = s->position()[0];
    double otherY = s->position()[1];
    double distance = sqrt(pow(thisX - otherX, 2) + pow(thisY - otherY, 2));
    distance = roundf(distance * 1000) / 1000;//Round off to 3 decimal places
    return distance;
}