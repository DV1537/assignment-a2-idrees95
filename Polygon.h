#ifndef POLYGON_H
#define POLYGON_H

class Polygon : public Shape 
{
public:
    Polygon(double* vertices,int numVertices);
    ~Polygon();

    std::string getType() const;
    double area();
    double circumference();
    double* position();
    bool isConvex();
    double distance(Shape *s);
private:
    double* vertices;
    double* XCords;
    double* YCords;
    int numVertices;
};


#endif /* POLYGON_H */

