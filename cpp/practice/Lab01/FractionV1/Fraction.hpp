#ifndef _FRACTION_HPP
#define _FRACTION_HPP

#include <iostream>
using namespace std;

class Fraction {
    private:
        int _num;
        int _den;
    public:
        // constructors
        Fraction();
        Fraction(int num, int den);

        // destructor
        ~Fraction();

        // getters
        int getNum() const;
        int getDen() const;

        // setters
        void setNum(int num);
        void setDen(int den);

        // other method
        Fraction optimaze() ;

        // overloading operators
        Fraction operator+(const Fraction f) const;
        Fraction operator-(const Fraction f) const;
        Fraction operator*(const Fraction f) const;
        Fraction operator/(const Fraction f) const;

        friend ostream& operator<<(ostream& os, const Fraction f);
        friend istream& operator>>(istream& is, Fraction& f);

};

#endif