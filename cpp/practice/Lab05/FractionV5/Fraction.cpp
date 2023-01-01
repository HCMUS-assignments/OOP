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

