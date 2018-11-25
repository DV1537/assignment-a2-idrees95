#include<iostream>
#include<string>
#include <cmath>
#include "Shape.h"
#include "Polygon.h"

Polygon::Polygon(double* vertices,int numVertices) 
{
    this->vertices = vertices;
    this->numVertices = numVertices;
    //Seperating cords for easy calculations
    this->XCords = new double[numVertices];
    this->YCords = new double[numVertices];
    for(int i =0;i<numVertices*2;i+=2){
        XCords[i/2] = vertices[i];
        YCords[i/2] = vertices[i+1];
    }
}

Polygon::~Polygon()
{
    delete[] XCords;
    delete[] YCords;
}

double Polygon::area()
{
    double area = 0;
    for (int i = 0; i < this->numVertices; ++i)
    {
       int j = (i + 1)%this->numVertices;
       area += 0.5 * (XCords[i]*YCords[j] -  XCords[j]*YCords[i]);
    }
    area = abs(area);
    area = roundf(area * 1000) / 1000;//Round off to 3 decimal places
    return area;
}

std::string Polygon::getType() const
{
    return "Polygon";
}

double Polygon::circumference(){
    double circumference = 0,dx,dy;
    for (int i = 0; i < this->numVertices; ++i)
    {
       int j = (i + 1)%this->numVertices;
       
       dx = pow(XCords[j]-XCords[i],2);
       dy = pow(YCords[j]-YCords[i],2);
       circumference += sqrt(dx + dy);  
    }
    circumference = roundf(circumference * 1000) / 1000;//Round off to 3 decimal places
    return circumference;
}
bool Polygon::isConvex(){
    if (this->numVertices < 4)
        return true;

    bool isConvex = false;

    for(int i = 0; i < this->numVertices; i++)
    {
        double dx1 = XCords[(i + 2) % this->numVertices] - XCords[(i + 1) % this->numVertices];
        double dy1 = YCords[(i + 2) % this->numVertices] - YCords[(i + 1) % this->numVertices];
        double dx2 = XCords[i] - XCords[(i + 1) % this->numVertices];
        double dy2 = YCords[i]- YCords[(i + 1) % this->numVertices];
        double zcrossproduct = dx1 * dy2 - dy1 * dx2;

        if (i == 0)
            isConvex = zcrossproduct > 0;
        else if (isConvex != (zcrossproduct > 0))
            return false;
    }
    return true;
}
double* Polygon::position(){
    double *pos = new double[2];
    pos[0] = 0;
    pos[1] = 0;
    for (int i = 0; i < this->numVertices; ++i)
    {
       pos[0] += XCords[i];
       pos[1] += YCords[i];
    }
    pos[0] /= numVertices;
    pos[1] /= numVertices; 
    pos[0] = roundf(pos[0] * 1000) / 1000;//Round off to 3 decimal places
    pos[1] = roundf(pos[1] * 1000) / 1000;//Round off to 3 decimal places
    return pos;
}
double Polygon::distance(Shape *s){
    double thisX = this->position()[0];
    double thisY = this->position()[1];
    double otherX = s->position()[0];
    double otherY = s->position()[1];
    double distance = sqrt(pow(thisX - otherX, 2) + pow(thisY - otherY, 2));
    distance = roundf(distance * 1000) / 1000;//Round off to 3 decimal places
    return distance;
}
