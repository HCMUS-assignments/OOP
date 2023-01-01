#include "Triangle.hpp"

Triangle::Triangle () {
    _a = Point();
    _b = Point();
    _c = Point();
}

Triangle::Triangle (Point a, Point b, Point c) {
    _a = a;
    _b = b;
    _c = c;
}

Triangle::~Triangle () {
    // Nothing to do here
}

Point Triangle::getA () {
    return _a;
}

Point Triangle::getB () {
    return _b;
}

Point Triangle::getC () {
    return _c;
}

void Triangle::setA (Point a) {
    _a = a;
}

void Triangle::setB (Point b) {
    _b = b;
}

void Triangle::setC (Point c) {
    _c = c;
}

float Triangle::getArea () {
    // heron's formula
    float p = getPerimeter() / 2;
    float side1 = _a.distance(_b);
    float side2 = _b.distance(_c);
    float side3 = _c.distance(_a);

    float area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
    return area;
    
}

float Triangle::getPerimeter () {
    //calculate the length of each side
    float side1 = _a.distance(_b);
    float side2 = _b.distance(_c);
    float side3 = _c.distance(_a);

    //calculate the perimeter
    float perimeter = side1 + side2 + side3;
    return perimeter;
}

ostream& operator << (ostream& os, const Triangle t) {
    os << "Triangle: " << t._a << ", " << t._b << ", " << t._c;
    return os;
}

istream& operator >> (istream& is, Triangle& t) {
    cout << "Enter point A: ";
    is >> t._a;
    cout << "Enter point B: ";
    is >> t._b;
    cout << "Enter point C: ";
    is >> t._c;
    return is;
}