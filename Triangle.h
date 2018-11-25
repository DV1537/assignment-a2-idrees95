#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape 
{
public:
    Triangle(double* vertices);
    std::string getType() const;
    double area();
    double circumference();
    double* position();
    bool isConvex();
    double distance(Shape *s);
private:
    double* vertices;
};

#endif /* TRIANGLE_H */

