#include "complexNumber.hpp"
#include <cmath>

ComplexNumber::ComplexNumber(double r, double i ) {
    this->r = r;
    this->i = i;
}

ComplexNumber::ComplexNumber(const ComplexNumber &c) {
    this->r = c.r;
    this->i = c.i;
}

void ComplexNumber::setReal (double r) {
    this->r = r;
}

void ComplexNumber::setImaginary (double i) {
    this->i = i;
}

double ComplexNumber::getReal() const {
    return this->r;
}

double ComplexNumber::getImaginary() const {
    return this->i;
}

double ComplexNumber::getModun() const {
    return sqrt(r*r + i*i);
}

// operator overloading methods

ComplexNumber ComplexNumber::operator+ (const ComplexNumber c) const {
    ComplexNumber temp;
    temp.r = r + c.r;
    temp.i = i + c.i;
    return temp;
}

ComplexNumber ComplexNumber::operator+= (ComplexNumber c) {
    r += c.r;
    i += c.i;
    return *this;
}

ComplexNumber ComplexNumber::operator- (const ComplexNumber c) const {
    ComplexNumber temp;
    temp.r = r - c.r;
    temp.i = i - c.i;
    return temp;

}

ComplexNumber ComplexNumber::operator-= (ComplexNumber c) {
    r -= c.r;
    i -= c.i;
    return *this;
}

ComplexNumber ComplexNumber::operator* (const ComplexNumber c) const {
    ComplexNumber temp;
    temp.r = r * c.r - i * c.i;
    temp.i = r * c.i + i * c.r;
    return temp;
}

ComplexNumber ComplexNumber::operator*= (ComplexNumber c) {
    double temp = r;
    r = r * c.r - i * c.i;
    i = temp * c.i + i * c.r;
    return *this;
}

ComplexNumber ComplexNumber::operator/ (const ComplexNumber c) const {
    // nhân cho số phức liên hợp của mẫu
    ComplexNumber temp;
    temp.r = (r * c.r + i * c.i ) / (c.r*c.r + c.i*c.i);
    temp.i = (c.r * i - r * c.i) / (c.r*c.r + c.i*c.i);

    return temp;
}

ComplexNumber ComplexNumber::operator/= (ComplexNumber c) {
    // nhân cho số phức liên hợp của mẫu
    double temp = r;
    r = (r * c.r + i * c.i ) / (c.r*c.r + c.i*c.i);
    i = (c.r * i - temp * c.i) / (c.r*c.r + c.i*c.i);

    return *this;

}

bool ComplexNumber::operator== (const ComplexNumber c) const {
    if (r == c.r && i == c.i ) {
        return true;
    }
    return false;
}

bool ComplexNumber::operator!= (const ComplexNumber c) const {
    if (r != c.r || i != c.i) {
        return true;
    }
    return false;
}

// friend functions

ostream &operator << (ostream &out, const ComplexNumber &c) {
    if (c.i >= 0) {
        out << c.r << " + " << c.i << "i";
    } else {
        out << c.r << " - " << -c.i << "i";
    }
    return out;
}

istream &operator >> (istream &in, ComplexNumber &c) {
    in >> c.r >> c.i;
    return in;
}