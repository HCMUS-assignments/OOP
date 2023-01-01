#include "Point.hpp"

Point::Point(){
    _x = 0;
    _y = 0;
    Point::instanceCount++;
}

Point::Point(const float x,  const float y){
    _x = x;
    _y = y;
    Point::instanceCount++;
}

Point::Point(const Point *&p){
    _x = p->_x;
    _y = p->_y;
    Point::instanceCount++;
}

Point::~Point(){

}

const float Point::X(){
    return _x;
}

const float Point::Y(){
    return _y;
}

void Point::SetX(const float x){
    _x = x;
}

void Point::SetY(const float y){
    _y = y;
}

float Point::CalcDistanceTo(const Point *p) const{
    return sqrt(pow(_x - p->_x, 2) + pow(_y - p->_y, 2));
}

float Point::CalcDistance(const Point* p1, const Point* p2){
    return p1->CalcDistanceTo(p2);
}

