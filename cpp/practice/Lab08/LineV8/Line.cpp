#include "Line.hpp"

Line :: Line () {
    _start = new Point();
    _end = new Point();
}

Line :: Line (Point *start, Point *end) {
    *_start = *start;
    *_end = *end;
}

Line :: Line (const Line& l) {
    _start = l._start;
    _end = l._end;
}

Line :: ~Line () {}

Point Line :: getStart () {
    return *_start;
}

Point Line :: getEnd () {
    return *_end;
}

void Line :: setStart (Point *start) {
    *_start = *start;
}

void Line :: setEnd (Point *end) {
    *_end = *end;
}

string Line :: toString () const {
    stringstream ss;
    ss << "Line: " << _start->toString() << " to " << _end->toString();
    return ss.str();
}

ostream & operator << (ostream &os, const Line *l) {
    os << l->toString();
    return os;
}

istream &operator >> (istream &is, Line *l) {
    cout << "Enter start point: " << endl;
    is >> l->_start;
    cout << "Enter end point: " << endl;
    is >> l->_end;
    return is;
}

Line* Line::Parse (string str) {
    string sep = ")";
    int start = 0;
    int found = str.find(sep, start);

    Line *obj = new Line();

    if (found != string::npos) {
        // solve
        string  _startPoint = str.substr(start, found - start + 1);     // => (a,b)
        // cout << "Start point in string: " << _startPoint << endl;
        obj->setStart(Point::Parse(_startPoint));

        found = str.find("(", found + 1);

        string _endPoint = str.substr(found , str.length() - found);
        // cout << "End point in string : " << _endPoint << endl;
        obj->setEnd(Point::Parse(_endPoint));
    }
    return obj;

}