#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP

#include "Point.hpp"
#include <iostream>
using namespace std;

const double PI = 3.14;

class Circle {
private:
    double _radius;
    Point _center;

public:
    // constructors
    Circle();
    Circle(double r, Point c);

    // copy constructor
    Circle(const Circle& c);

    // destructor
    ~Circle();

    // getters
    double getRadius() const;
    Point getCenter() const;

    // setters
    void setRadius(double r);
    void setCenter(Point c);

    // other methods
    double getArea() const;
    double getPerimeter() const;

    string toString() const;
};

#endif