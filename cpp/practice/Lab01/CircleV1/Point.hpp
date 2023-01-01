#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
using namespace std;

class Point {
    private:
        float _x;
        float _y;
    public:
        //default constructor
        Point() {
            _x = 0;
            _y = 0;
        }

        //fully-parameterized constructor
        Point(float x, float y) {
            _x = x;
            _y = y;
        }

        // destructor
        ~Point() {}

        //getter for x and y
        float getX() { return _x;}
        float getY() { return _y;}

        //setter for x and y
        void setX(float x) { _x = x;}
        void setY(float y) { _y = y;}

        friend ostream& operator << (ostream& os, const Point p) {
            os << "(" << p._x << ", " << p._y << ")";
            return os;
        }

        friend istream& operator >> (istream& is, Point& p) {
            is >> p._x >> p._y;
            return is;
        }
};

#endif