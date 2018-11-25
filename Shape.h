#ifndef SHAPE_H
#define SHAPE_H
#include<string>

class Shape 
{
public:
    virtual std::string getType() const = 0;
    virtual double area();
    virtual double circumference();
    virtual double* position();
    virtual bool isConvex();
    virtual double distance(Shape *s);
private:

};

#endif /* SHAPE_H */

