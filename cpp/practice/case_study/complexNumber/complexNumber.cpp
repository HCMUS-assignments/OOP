#include "complexNumber.hpp"

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

// operator overloading methods

ComplexNumber ComplexNumber::operator+ (const ComplexNumber c) const {

}

ComplexNumber ComplexNumber::operator- (const ComplexNumber c) const {

}

ComplexNumber ComplexNumber::operator* (const ComplexNumber c) const {

}

ComplexNumber ComplexNumber::operator/ (const ComplexNumber c) const {

}

bool ComplexNumber::operator== (const ComplexNumber c) const {

}

bool ComplexNumber::operator!= (const ComplexNumber c) const {

}

// friend functions

ostream &operator << (ostream &out, const ComplexNumber &c) {

}

istream &operator >> (istream &in, ComplexNumber &c) {

}