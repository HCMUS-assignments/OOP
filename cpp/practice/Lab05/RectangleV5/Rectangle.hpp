#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include "Point.hpp"
#include <iostream>
using namespace std;

class Rectangle {
    private: 
        Point _topLeft;
        Point _bottomRight;
    public:
        // Constructor
        Rectangle (Point topLeft = Point(), Point bottomRight = Point());

        // Copy constructor
        Rectangle (const Rectangle &r);

        // Destructor
        ~Rectangle();

        // Getter
        Point getTopLeft ();
        Point getBottomRight ();

        // Setter
        void setTopLeft (Point topLeft);
        void setBottomRight (Point bottomRight);

        // Other methods
        float getArea ();
        float getPerimeter ();

        string toString ();



};

#endif