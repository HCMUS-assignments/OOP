#ifndef _TRIANGLE_HPP
#define _TRIANGLE_HPP

#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
    private:
        Point _a;
        Point _b;
        Point _c;
    public:
        // Constructors
        Triangle ();
        Triangle (Point a, Point b, Point c);

        // Copy constructor
        Triangle (const Triangle &t);

        // Destructor
        ~Triangle ();

        // Getters and setters
        Point getA ();
        Point getB ();
        Point getC ();
        void setA (Point a);
        void setB (Point b);
        void setC (Point c);

        // Other methods
        float getArea ();
        float getPerimeter ();
        string toString ();
  
};

#endif