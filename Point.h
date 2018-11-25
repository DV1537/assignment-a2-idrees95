#ifndef POINT_H
#define POINT_H

class Point : public Shape 
{
public:
    Point(double* vertices);
    std::string getType() const;
    double area();
    double circumference();
    double* position();
    bool isConvex();
    double distance(Shape *s);
private:
    double* vertices;
};

#endif /* POINT_H */

