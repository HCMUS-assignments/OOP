#include "Circle.hpp"

Circle::Circle() {
    _radius = 0;
    _center = new Point();
}

Circle::Circle(double r, Point *c) {
    _radius = r;
    *_center = *c;
}

Circle::Circle(const Circle& c) {
    _radius = c._radius;
    _center = c._center;
}

Circle::~Circle() {
    // nothing to do
}

double Circle::getRadius() const {
    return _radius;
}

Point Circle::getCenter() const {
    return *_center;
}

void Circle::setRadius(double r) {
    _radius = r;
}

void Circle::setCenter(Point *c) {
    *_center = *c;
}

double Circle::getArea() const {
    return PI * _radius * _radius;
}

double Circle::getPerimeter() const {
    return 2 * PI * _radius;
}

string Circle::toString() const {
    stringstream ss;
    ss << "Circle: center = " << _center->toString() << ", radius = " << _radius;
    return ss.str();
}

istream& operator>>(istream& is, Circle* c) {
    cout << "Enter the radius: ";
    is >> c->_radius;
    cout << "Enter the center: ";
    is >> c->_center;
    return is;
}

ostream& operator<<(ostream& os, const Circle* c) {
    os << c->toString();
    return os;
}