#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include "Point.hpp"
#include <iostream>
using namespace std;

class Rectangle {
    private:
        Point *_topLeft;
        Point *_bottomRight;

    public:
        static int InstanceCount;

    public:
        // constructors
        Rectangle();
        Rectangle(const Point *topLeft, const Point *bottomRight);

        // copy constructor
        Rectangle(const Rectangle &r);

        // destructor
        ~Rectangle();

        // getters
        const Point* TopLeft();
        const Point* BottomRight();

        // setters
        void SetTopLeft(const Point *topLeft);
        void SetBottomRight(const Point *bottomRight);

        // methods
        float CalcArea() const;
        float CalcPerimeter() const;
};

#endif
