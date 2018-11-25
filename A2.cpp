#include <iostream>
#include <string>
#include <fstream>

#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

using namespace std;

int readVertices(string filename,double *&vertices)
{
    double number;
    int size = 0;
    ifstream input;
    input.open(filename);
    
    if(input.is_open())
    { 
        //get size
        while (input >> number)
        {
            size++;
        } 
        input.close();
        
        vertices = new double[size];
        input.open(filename);
        if(input.is_open())
        {
            int i = 0;
            while (input >> vertices[i])
            {
                i++;
            } 
            input.close();
        
        }
    }
    else
    {
        std::cout << "ERROR" << std::endl;
    }
    return size;
}

void printShapeDetails(Shape *s)
{
    /* Test shape for distance calculation*/
    Shape *s1;
    double* ver2 = new double[2];
    ver2[0] = 2;
    ver2[1] = 10;
    s1 = new Point(ver2);
    
    cout<<" -Created shape is "<<s->getType()<<endl;
    cout<<" -The area of shape is "<<s->area()<<endl;
    cout<<" -The (center) position of shape is  ("<<s->position()[0]<<","<<s->position()[1]<<")"<<endl;
    cout<<" -The distance from test point ("<<ver2[0]<<","<<ver2[1]<<") is "<<s->distance(s1)<<endl;
    cout<<" -The circumference of shape is "<<s->circumference()<<endl;
    cout<<" -Is shape convex "<<s->isConvex()<<endl;
}

int main(int argc, char const *argv[])
{ 
    Shape *s;
    double* vertices;
    int size = readVertices(argv[1],vertices);
    cout<<"Read Vertices from "<<argv[1]<<" are : ";
    for(int i =0;i<size;i+=2){
        cout<<"("<<vertices[i]<<","<<vertices[i+1]<<") ";
    }
    cout<<endl<<endl;
    if(size%2==0 && size > 0){
        if(size==2){ // A point has 1 vertex (2 numbers)
            s = new Point(vertices);
        }
        else if(size==4){ // A Line has 2 vertices (4 numbers)
            s = new Line(vertices);
        }
        else if(size==6){ // A Triangle has 3 vertices (6 numbers)
            s = new Triangle(vertices);
        }
        else{ // Any shape more than three vertices is polygon
            s = new Polygon(vertices,size/2);
        }
        printShapeDetails(s);
    }
    else{
        cout<<"Numbers provided in file are not even or zero. Unable to create coordinates";
    }
    
    return 0;
}