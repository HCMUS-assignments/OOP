#include "Rectangle.hpp"

Rectangle::Rectangle(){
    _topLeft = new Point();
    _bottomRight = new Point();
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Point *topLeft, const Point *bottomRight){
    _topLeft = new Point(*topLeft);
    _bottomRight = new Point(*bottomRight);
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Rectangle &r){
    _topLeft = new Point(*r._topLeft);
    _bottomRight = new Point(*r._bottomRight);
    Rectangle::InstanceCount++;
}

Rectangle::~Rectangle(){
    delete _topLeft;
    delete _bottomRight;
}

const Point* Rectangle::TopLeft(){
    return _topLeft;
}

const Point* Rectangle::BottomRight(){
    return _bottomRight;
}

void Rectangle::SetTopLeft(const Point *topLeft){
    _topLeft = new Point(*topLeft);
}

void Rectangle::SetBottomRight(const Point *bottomRight){
    _bottomRight = new Point(*bottomRight);
}

float Rectangle::CalcArea() const{
    return abs ((_bottomRight->X() - _topLeft->X()) * (_topLeft->Y() - _bottomRight->Y()));
}

float Rectangle::CalcPerimeter() const{
    return 2 * (abs (_bottomRight->X() - _topLeft->X()) + abs (_topLeft->Y() - _bottomRight->Y()));
}


