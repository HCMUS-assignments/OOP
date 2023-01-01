#include "Line.hpp"

Line :: Line () {
    _start = Point();
    _end = Point();
}

Line :: Line (Point start, Point end) {
    _start = start;
    _end = end;
}

Line :: Line (const Line& l) {
    _start = l._start;
    _end = l._end;
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

string Line :: toString () {
    stringstream ss;
    ss << "Line: " << _start.toString() << " to " << _end.toString();
    return ss.str();
}

