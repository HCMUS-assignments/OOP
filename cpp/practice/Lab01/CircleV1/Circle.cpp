#include "Circle.hpp"

Circle::Circle() {
    _radius = 0;
    _center = Point();
}

Circle::Circle(double r, Point c) {
    _radius = r;
    _center = c;
}

Circle::~Circle() {
    // nothing to do
}

double Circle::getRadius() const {
    return _radius;
}

Point Circle::getCenter() const {
    return _center;
}

void Circle::setRadius(double r) {
    _radius = r;
}

void Circle::setCenter(Point c) {
    _center = c;
}

double Circle::getArea() const {
    return PI * _radius * _radius;
}

double Circle::getPerimeter() const {
    return 2 * PI * _radius;
}

ostream& operator<<(ostream& os, const Circle c) {
    os << "Circle: radius = " << c._radius << ", center = " << c._center;
    return os;
}

istream& operator>>(istream& is, Circle& c) {
    cout << "Enter radius: ";
    is >> c._radius;
    cout << "Enter center: ";
    is >> c._center;
    return is;
}
