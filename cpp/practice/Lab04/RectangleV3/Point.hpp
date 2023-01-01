#ifndef _POINT_HPP
#define _POINT_HPP

#include <cmath>
#include <iostream>
using namespace std;

class Point{
    private:
        float _x;
        float _y;

    public:
        static int instanceCount;
    public:
        // constructor
        Point();
        Point(const float x, const float y );

        // copy constructor
        Point( const Point &p);

        // destructor
        ~Point();

        // getters
        const float X();
        const float Y();

        // setters
        void SetX(const float x);
        void SetY(const float y);

        // methods
        float CalcDistanceTo(const Point *p) const;
        static float CalcDistance(const Point* p1, const Point* p2);

};

#endif