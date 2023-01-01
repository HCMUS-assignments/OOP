#include "Rectangle.hpp"

Rectangle::Rectangle (Point topLeft, Point bottomRight) {
    _topLeft = topLeft;
    _bottomRight = bottomRight;
}

Rectangle::Rectangle (const Rectangle &r) {
    _topLeft = r._topLeft;
    _bottomRight = r._bottomRight;
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

string Rectangle::toString () {
    return "Rectangle: " + _topLeft.toString() + " " + _bottomRight.toString();
}
