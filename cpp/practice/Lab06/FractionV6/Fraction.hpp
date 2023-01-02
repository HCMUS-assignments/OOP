#ifndef _FRACTION_HPP
#define _FRACTION_HPP

#include <iostream>
#include <sstream>
using namespace std;

class Fraction {
    private:
        int _num;
        int _den;
    public:
        // constructors
        Fraction();
        Fraction(int num, int den);

        // copy constructor
        Fraction(const Fraction &f);

        // destructor
        ~Fraction();

        // getters
        int getNum() const;
        int getDen() const;

        // setters
        void setNum(int num);
        void setDen(int den);

        string toString() const;


        // overload operators
        friend istream& operator>>(istream& is, Fraction* f);
        friend ostream& operator<<(ostream& os, const Fraction* f);

        

    

};

#endif