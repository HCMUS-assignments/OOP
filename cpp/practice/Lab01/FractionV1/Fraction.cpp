#include "Fraction.hpp"

Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    _num = num;
    _den = den;
}

Fraction::~Fraction() {
    // nothing to do
}

int Fraction::getNum() const {
    return _num;
}

int Fraction::getDen() const {
    return _den;
}

void Fraction::setNum(int num) {
    _num = num;
}

void Fraction::setDen(int den) {
    _den = den;
}

Fraction Fraction::optimaze() {
    int gcd = _num;
    int tmp = _den;
    while (tmp != 0) {
        int r = gcd % tmp;
        gcd = tmp;
        tmp = r;
    }
    _num /= gcd;
    _den /= gcd;

    if (_den < 0) {
        _num *= -1;
        _den *= -1;
    }

    return *this;
}

Fraction Fraction::operator+(const Fraction f) const {
    Fraction result;
    result._num = _num * f._den + _den * f._num;
    result._den = _den * f._den;
    return result.optimaze();
}

Fraction Fraction::operator-(const Fraction f) const {
    Fraction result;
    result._num = _num * f._den - _den * f._num;
    result._den = _den * f._den;
    return result.optimaze();
}

Fraction Fraction::operator*(const Fraction f) const {
    Fraction result;
    result._num = _num * f._num;
    result._den = _den * f._den;
    return result.optimaze();
}

Fraction Fraction::operator/(const Fraction f) const {
    Fraction result;
    result._num = _num * f._den;
    result._den = _den * f._num;
    return result.optimaze();
}

ostream& operator<<(ostream& os, const Fraction f) {
    os << f._num << "/" << f._den;
    return os;
}

istream& operator>>(istream& is, Fraction& f) {
    cout << "Enter numerator, denominator: ";
    is >> f._num >> f._den;
    return is;
}