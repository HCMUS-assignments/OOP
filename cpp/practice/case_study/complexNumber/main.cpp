#include "complexNumber.hpp"


int main() {
    ComplexNumber c1(1, 2);
    ComplexNumber c2(3, 4);
    ComplexNumber c3 = c1 + c2;
    ComplexNumber c4;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;

    // get real part
    cout << "Real part of c1: " << c1.getReal() << endl;
    cout << "Real part of c2: " << c2.getReal() << endl;
    cout << "Real part of c3: " << c3.getReal() << endl;
    cout << "Real part of c4: " << c4.getReal() << endl;

    // get imaginary part
    cout << "Imaginary part of c1: " << c1.getImaginary() << endl;
    cout << "Imaginary part of c2: " << c2.getImaginary() << endl;
    cout << "Imaginary part of c3: " << c3.getImaginary() << endl;
    cout << "Imaginary part of c4: " << c4.getImaginary() << endl;

    // get modun
    cout << "Modun of c1: " << c1.getModun() << endl;
    cout << "Modun of c2: " << c2.getModun() << endl;
    cout << "Modun of c3: " << c3.getModun() << endl;
    cout << "Modun of c4: " << c4.getModun() << endl;

    // enter c5, c6
    ComplexNumber c5, c6;
    cout << "Enter c5: ";
    cin >> c5;
    cout << "Enter c6: ";
    cin >> c6;
    cout << "c5: " << c5 << endl;
    cout << "c6: " << c6 << endl;

    // c5 + c6
    ComplexNumber c7 = c5 + c6;
    cout << "c5 + c6: " << c7 << endl;

    // c5 - c6
    ComplexNumber c8 = c5 - c6;
    cout << "c5 - c6: " << c8 << endl;

    // c5 * c6
    ComplexNumber c9 = c5 * c6;
    cout << "c5 * c6: " << c9 << endl;

    // c5 += c6
    c5 += c6;
    cout << "c5 += c6: " << c5 << endl;

    // c5 -= c6
    c5 -= c6;
    cout << "c5 -= c6: " << c5 << endl;

    // c5 / c6
    ComplexNumber c10 = c5 / c6;
    cout << "c5 / c6: " << c10 << endl;

    // is c5 == c6
    if (c5 == c6) {
        cout << "c5 == c6" << endl;
    } else {
        cout << "c5 != c6" << endl;
    }

    // is c5 != c6
    if (c5 != c6) {
        cout << "c5 != c6" << endl;
    } else {
        cout << "c5 == c6" << endl;
    }


    return 0;
}