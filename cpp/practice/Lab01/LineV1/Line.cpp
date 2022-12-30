#include "Line.hpp"

Line :: Line () {
    _start = Point();
    _end = Point();
}

Line :: Line (Point start, Point end) {
    _start = start;
    _end = end;
}

Line :: ~Line () {}

Point Line :: getStart () {
    return _start;
}

Point Line :: getEnd () {
    return _end;
}

void Line :: setStart (Point start) {
    _start = start;
}

void Line :: setEnd (Point end) {
    _end = end;
}

ostream& operator << (ostream &os, const Line l) {
    os << l._start << " " << l._end;
    return os;
}

istream& operator >> (istream &is, Line &l) {
    cout << "Enter start point: ";
    is >> l._start;
    cout << "Enter end point: ";
    is >> l._end;
    return is;
} 

