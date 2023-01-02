#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include <sstream>
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

        //copy constructor
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

        string toString() const {
            stringstream ss;
            ss << "(" << _x << ", " << _y << ")";
            return ss.str();
        }

        float calcDistanceTo( const Point *other) const{
            return sqrt(pow(_x - other->_x, 2) + pow(_y - other->_y, 2));
        }

        static float calcDistanceBetween(const Point *p1, const Point *p2) {
            return sqrt(pow(p1->_x - p2->_x, 2) + pow(p1->_y - p2->_y, 2));
        }

        // operator overloading
        friend istream& operator>>(istream& is, Point* p) {
            is >> p->_x;
            is >> p->_y;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Point* p) {
            os << p->toString();
            return os;
        }


};

#endif