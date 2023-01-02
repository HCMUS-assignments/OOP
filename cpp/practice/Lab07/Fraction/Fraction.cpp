#include "Fraction.hpp"

Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    _num = num;
    _den = den;
}

Fraction::Fraction(const Fraction &f) {
    _num = f._num;
    _den = f._den;
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

string Fraction::toString() const {
    stringstream ss;
    ss << _num << "/" << _den;
    return ss.str();
}

Fraction Fraction::getInverse() const {
    if (_num == 0) {
        return Fraction(0, 1);
    }
    Fraction f = Fraction(_den, _num);
    return f;
}

bool Fraction::isOptimized() const {
    int a = _num;
    int b = _den;
    int c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    if (a == 1) {
        return true;
    }
    return false;
}

void Fraction::optimize() {
    int a = _num;
    int b = _den;
    int c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    _num /= a;
    _den /= a;
}

ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.toString();
    return os;
}
