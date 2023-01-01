#include "Rectangle.hpp"

Rectangle::Rectangle() {
    _topLeft = new Point(1,1);
    _bottomRight = new Point(10,10);
}

Rectangle::Rectangle (Point *topLeft, Point *bottomRight) {
    *_topLeft = *topLeft;
    *_bottomRight = *bottomRight;
}

Rectangle::~Rectangle() {
    delete _topLeft;
    delete _bottomRight;
}

Point Rectangle::getTopLeft () {
    return *_topLeft;
}

Point Rectangle::getBottomRight () {
    return *_bottomRight;
}

void Rectangle::setTopLeft (Point *topLeft) {
    *_topLeft = *topLeft;
}

void Rectangle::setBottomRight (Point *bottomRight) {
    *_bottomRight = *bottomRight;
}

float Rectangle::getArea () {
    float width = _bottomRight->getX() - _topLeft->getX();
    float height = _topLeft->getY() - _bottomRight->getY();
    return width * height;
}

float Rectangle::getPerimeter () {
    float width = _bottomRight->getX() - _topLeft->getX();
    float height = _topLeft->getY() - _bottomRight->getY();
    return 2 * (width + height);
}

ostream& operator << (ostream& os, const Rectangle* r) {
    os << "Top left: " << r->_topLeft << endl;
    os << "Bottom right: " << r->_bottomRight << endl;
    return os;
}

istream& operator >> (istream& is, Rectangle*& r) {
    cout << "Enter top left: ";
    is >> r->_topLeft;
    cout << "Enter bottom right: ";
    is >> r->_bottomRight;
    return is;
}