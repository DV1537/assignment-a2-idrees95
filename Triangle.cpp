#include<string>
#include <cmath>
//using namespace std;
#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle(double* vertices) 
{
    this->vertices = vertices;
}

double Triangle::area(){
    double Ax = vertices[0];
    double Ay = vertices[1];
    double Bx = vertices[2];
    double By = vertices[3];
    double Cx = vertices[4];
    double Cy = vertices[5];
    double area = ( Ax*(By-Cy) + Bx*(Cy-Ay) + Cx*(Ay-By))/2;
    area = abs(area);
    area = roundf(area * 1000) / 1000;//Round off to 3 decimal places
    return area;
}
std::string Triangle::getType() const
{
    return "Triangle";
}

double Triangle::circumference()
{
    double side1 = sqrt(pow(vertices[0] - vertices[2], 2) + pow(vertices[1] - vertices[3], 2));
    double side2 = sqrt(pow(vertices[2] - vertices[4], 2) + pow(vertices[3] - vertices[5], 2));
    double side3 = sqrt(pow(vertices[4] - vertices[0], 2) + pow(vertices[5] - vertices[1], 2));
    
    double circumference = side1+side2+side3;
    circumference = roundf(circumference * 1000) / 1000;//Round off to 3 decimal places
    return circumference;
}

bool Triangle::isConvex()
{
    //any shape less than 3 vertices is convex
    return true;
}

double* Triangle::position()
{
    double Ax = vertices[0];
    double Ay = vertices[1];
    double Bx = vertices[2];
    double By = vertices[3];
    double Cx = vertices[4];
    double Cy = vertices[5];
    
    double *pos = new double[2];
    pos[0] = (Ax+Bx+Cx)/3;
    pos[1] = (Ay+By+Cy)/3;
    pos[0] = roundf(pos[0] * 1000) / 1000;//Round off to 3 decimal places
    pos[1] = roundf(pos[1] * 1000) / 1000;//Round off to 3 decimal places
    return pos;
}

double Triangle::distance(Shape *s)
{
    double thisX = this->position()[0];
    double thisY = this->position()[1];
    double otherX = s->position()[0];
    double otherY = s->position()[1];
    double distance = sqrt(pow(thisX - otherX, 2) + pow(thisY - otherY, 2));
    distance = roundf(distance * 1000) / 1000;//Round off to 3 decimal places
    return distance;
}