#ifndef LINE_HPP
#define LINE_HPP

#include <iostream>
#include "Point.hpp"
using namespace std;

class Line {
    private: 
        Point _start;
        Point _end;
    public:
        // default constructor
        Line () ;

        // fully-parameterized constructor
        Line (Point start, Point end) ;

        // destructor
        ~Line () ;

    
    public:
        // getter for start and end
        Point getStart () ;
        Point getEnd () ;

        // setter for start and end
        void setStart (Point start) ;
        void setEnd (Point end) ;

        // operator overloading
        friend ostream& operator << (ostream& os, const Line l) ;
        friend istream& operator >> (istream& is, Line& l) ; 
    
};

#endif
