#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;

class Rectangle {
    private: 
        Point *_topLeft;
        Point *_bottomRight;
    public:
        // Constructor
        Rectangle();
        Rectangle (Point *topLeft, Point *bottomRight);

        // Destructor
        ~Rectangle();

        // Getter
        Point getTopLeft ();
        Point getBottomRight ();

        // Setter
        void setTopLeft (Point *topLeft);
        void setBottomRight (Point *bottomRight);

        // Other methods
        float getArea ();
        float getPerimeter ();

        // operator overloading
        friend ostream& operator << (ostream& os, const Rectangle *r);
        friend istream& operator >> (istream& is, Rectangle*& r);

};

#endif