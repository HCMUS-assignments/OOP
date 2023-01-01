#ifndef _LINE_HPP
#define _LINE_HPP

#include "Point.hpp"

class Line {
    private:
        Point *_start;
        Point *_end;

    public:
        static int InstanceCount;
    public:
        // constructor
        Line();
        Line(const Point *start, const Point *end);

        // destructor
        ~Line();

        // getters
        const Point* Start();
        const Point* End();

        // setters
        void SetStart(const Point *start);
        void SetEnd(const Point *end);

        // methods
        float Length() const;

};

#endif