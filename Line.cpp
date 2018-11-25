#include<string>
#include <cmath>
using namespace std;
#include "Shape.h"
#include "Line.h"

Line::Line(double* vertices) 
{
    this->vertices = vertices;
}

double Line::area()
{
    //As per multiple online resources area of line = length of line
    double length = sqrt(pow(vertices[0] - vertices[2], 2) + pow(vertices[1] - vertices[3], 2));
    length = roundf(length * 1000) / 1000;//Round off to 3 decimal places
    return length;
}

std::string Line::getType() const
{
    return "Line";
}

double Line::circumference()
{
    return this->area();// as both are equal to length of line
}

bool Line::isConvex()
{
    //any shape less than 3 vertices is convex
    return true;
}

double* Line::position()
{
    double *pos = new double[2];
    pos[0] = (vertices[0]+vertices[2])/2;
    pos[1] = (vertices[1]+vertices[3])/2;
    pos[0] = roundf(pos[0] * 1000) / 1000;//Round off to 3 decimal places
    pos[1] = roundf(pos[1] * 1000) / 1000;//Round off to 3 decimal places
    return pos;
}

double Line::distance(Shape *s){
    double thisX = this->position()[0];
    double thisY = this->position()[1];
    double otherX = s->position()[0];
    double otherY = s->position()[1];
    double distance = sqrt(pow(thisX - otherX, 2) + pow(thisY - otherY, 2));
    distance = roundf(distance * 1000) / 1000;//Round off to 3 decimal places
    return distance;
}