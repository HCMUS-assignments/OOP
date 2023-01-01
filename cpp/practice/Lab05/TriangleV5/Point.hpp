#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <sstream>
#include <cmath>
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

        // copy constructor
        Point(const Point& p) {
            _x = p._x;
            _y = p._y;
        }

        // destructor
        ~Point() {}

        //getter for x and y
        float getX() { return _x;}
        float getY() { return _y;}

        //setter for x and y
        void setX(float x) { _x = x;}
        void setY(float y) { _y = y;}

        // distance between two points
        float distance(Point p) {
            float xDiff = _x - p._x;
            float yDiff = _y - p._y;
            return sqrt(xDiff * xDiff + yDiff * yDiff);
        }

        string toString() {
            stringstream ss;
            ss << "(" << _x << ", " << _y << ")";
            return ss.str();

        }

    
};

#endif