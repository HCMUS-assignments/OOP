#include "Line.hpp"

Line::Line(){
    _start = new Point();
    _end = new Point();
    Line::InstanceCount++;
}

Line::Line(const Point *start, const Point *end){
    _start = new Point(*start);
    _end = new Point(*end);
    Line::InstanceCount++;
}

Line::Line(const Line &line){
    _start = new Point(line.Start());
    _end = new Point(line.End());
    Line::InstanceCount++;
}

Line::~Line(){
    delete _start;
    delete _end;
}

const Point Line::Start() const{
    return *_start;
}

const Point Line::End() const{
    return *_end;
}

void Line::SetStart(const Point *start){
    _start = new Point(*start);
}

void Line::SetEnd(const Point *end){
    _end = new Point(*end);
}

float Line::Length() const{
    return Point::CalcDistance(_start, _end);
}

