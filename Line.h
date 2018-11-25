#ifndef LINE_H
#define LINE_H

class Line  : public Shape {
public:
    Line(double* vertices);
    
    std::string getType() const;
    double area();
    double circumference();
    double* position();
    bool isConvex();
    double distance(Shape *s);

private:
    double* vertices;
};

#endif /* LINE_H */

