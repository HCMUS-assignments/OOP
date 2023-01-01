#include "Fraction.hpp"

int main() {
    Fraction f1(1, 2);
    Fraction f2(2, 3);

    Fraction f3(f1);
    Fraction f4(f2);

    cout << "f1 = " << f1.toString() << endl;
    cout << "f2 = " << f2.toString() << endl;
    cout << "f3 = " << f3.toString() << endl;
    cout << "f4 = " << f4.toString() << endl;

    return 0;
}