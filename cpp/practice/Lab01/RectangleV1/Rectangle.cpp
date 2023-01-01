#include "Rectangle.hpp"

Rectangle::Rectangle (Point topLeft, Point bottomRight) {
    _topLeft = topLeft;
    _bottomRight = bottomRight;
}

Rectangle::~Rectangle() {}

Point Rectangle::getTopLeft () {
    return _topLeft;
}

Point Rectangle::getBottomRight () {
    return _bottomRight;
}

void Rectangle::setTopLeft (Point topLeft) {
    _topLeft = topLeft;
}

void Rectangle::setBottomRight (Point bottomRight) {
    _bottomRight = bottomRight;
}

float Rectangle::getArea () {
    float width = _bottomRight.getX() - _topLeft.getX();
    float height = _topLeft.getY() - _bottomRight.getY();
    return width * height;
}

float Rectangle::getPerimeter () {
    float width = _bottomRight.getX() - _topLeft.getX();
    float height = _topLeft.getY() - _bottomRight.getY();
    return 2 * (width + height);
}

ostream& operator << (ostream& os, const Rectangle& r) {
    os << "Top left: " << r._topLeft << endl;
    os << "Bottom right: " << r._bottomRight << endl;
    return os;
}

istream& operator >> (istream& is, Rectangle& r) {
    cout << "Enter top left - bottom right: ";
    is >> r._topLeft >> r._bottomRight;
    return is;
}